/*
  Copyright 2019 www.dev5.cn, Inc. dev5@qq.com
 
  This file is part of X-MSG-IM.
 
  X-MSG-IM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  X-MSG-IM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU Affero General Public License
  along with X-MSG-IM.  If not, see <https://www.gnu.org/licenses/>.
 */
/*
 * main.cpp
 *
 *  Created on: 2019年5月12日 下午11:53:10
 *      Author: dev5@qq.com
 */

#include "XmsgTcpLog.h"
#include "XmsgHttpLog.h"
#include "XmsgWebSocketLog.h"
#include "net-x-msg-im-auth.pb.h"

#define X_MSG_N2H_PRPC_BEFOR_AUTH(__MSGMGR__, __BEGIN__, __END__, __CB__)					(__MSGMGR__->reg(__BEGIN__::descriptor(), __END__::descriptor(), NULL, (void*)(__CB__), false));

static void x_msg_im_auth_simple(shared_ptr<XscChannel> channel, SptrXitp trans, shared_ptr<XmsgImAuthSimpleReq> req);

int main(int argc, char **argv)
{
	Log::setRecord();
	Xsc::init(); /* libxsc-cpp初始化. */
	//
	shared_ptr<XscTcpServer> tcpServer(new XscTcpServer("tcp-server", shared_ptr<XmsgTcpLog>(new XmsgTcpLog())));
	shared_ptr<XscTcpCfg> tcpCfg(new XscTcpCfg());
	tcpCfg->addr = "0.0.0.0:1224";
	if (!tcpServer->startup(tcpCfg) || !tcpServer->publish()) /* tcp服务器启动. */
		return EXIT_FAILURE;
	//
	shared_ptr<XscHttpServer> httpServer(new XscHttpServer("http-server", shared_ptr<XmsgHttpLog>(new XmsgHttpLog())));
	shared_ptr<XscHttpCfg> httpCfg(new XscHttpCfg());
	httpCfg->addr = "0.0.0.0:1225";
	if (!httpServer->startup(httpCfg) || !httpServer->publish()) /* http服务器启动. */
		return EXIT_FAILURE;
	//
	shared_ptr<XscWebSocketServer> webSocketServer(new XscWebSocketServer("web-socket-server", shared_ptr<XmsgWebSocketLog>(new XmsgWebSocketLog())));
	shared_ptr<XscWebSocketCfg> webSocketCfg(new XscWebSocketCfg());
	webSocketCfg->addr = "0.0.0.0:1226";
	if (!webSocketServer->startup(webSocketCfg) || !webSocketServer->publish()) /* websocket服务器启动. */
		return EXIT_FAILURE;
	//
	shared_ptr<XmsgImN2HMsgMgr> msgMgrTcp(new XmsgImN2HMsgMgr(tcpServer)); /* 服务器上的消息管理器. */
	shared_ptr<XmsgImN2HMsgMgr> msgMgrHttp(new XmsgImN2HMsgMgr(httpServer));
	shared_ptr<XmsgImN2HMsgMgr> msgMgrWebSocket(new XmsgImN2HMsgMgr(webSocketServer));
	//
	X_MSG_N2H_PRPC_BEFOR_AUTH(msgMgrTcp, XmsgImAuthSimpleReq, XmsgImAuthSimpleRsp, x_msg_im_auth_simple /* 消息注册. */)
	X_MSG_N2H_PRPC_BEFOR_AUTH(msgMgrHttp, XmsgImAuthSimpleReq, XmsgImAuthSimpleRsp, x_msg_im_auth_simple)
	X_MSG_N2H_PRPC_BEFOR_AUTH(msgMgrWebSocket, XmsgImAuthSimpleReq, XmsgImAuthSimpleRsp, x_msg_im_auth_simple)
	//
	Misc::hold();
	return EXIT_FAILURE;
}

/* 在这里处理消息. */
void x_msg_im_auth_simple(shared_ptr<XscChannel> channel, SptrXitp trans, shared_ptr<XmsgImAuthSimpleReq> req)
{
	/**
	 *
	 * channel即网络信道, 这里是客户端连接.
	 *
	 * trans即network transaction, 一切消息都以事务开始, 以事务结束.
	 *
	 */
	thread t([trans, req]() /* 事务总是在channel归属的线程开始, 却可以在任意线程上结束. */
	{
		shared_ptr<XmsgImAuthSimpleRsp> rsp(new XmsgImAuthSimpleRsp());
		rsp->set_token("token");
		trans->end(rsp); /* 结束事务. */
	});
	t.detach();
}
