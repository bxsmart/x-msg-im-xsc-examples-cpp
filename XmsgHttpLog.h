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
 * XmsgHttpLog.h
 *
 *  Created on: 2019年11月6日 下午5:42:05
 *      Author: xzwdev
 */

#ifndef XMSGHTTPLOG_H_
#define XMSGHTTPLOG_H_

#include <libx-msg-im-xsc.h>

/**
 *
 * 对外http服务器上的消息日志.
 *
 */
class XmsgHttpLog: public XmsgImHttpLog
{
public:
	shared_ptr<XscHttpChannel> newXscHttpChannel(shared_ptr<XscHttpWorker> wk, int cfd, const string& peer); /* 当连接到来时, 构造一个n2h方向的XscHttpChannel的子类. */
	void didaMainThread(ullong now); /* 定时器振荡, 仅在主线程上. */
	void dida(ullong now); /* 定时器振荡, 需要注意是, 此函数会在每个XscHttpWorker线程上都触发一次. 因此, 在此函数中操作ThreadLocal变量是安全的. */
	void rx(XscChannel* channel, uchar* dat, int len); /* XscTcpChannel上的入栈消息. */
	void tx(XscChannel* channel, uchar* dat, int len); /* XscTcpChannel上的出栈消息. */
	void transInitStart(SptrXiti trans, shared_ptr<XscProtoPdu> pdu /* 出栈报文. */); /* 一个主动型事务开始. */
	void transInitFinished(SptrXiti trans, shared_ptr<XscProtoPdu> pdu /* 入栈报文(可能为空). */); /* 一个主动型事务结束. */
	void transPassStart(SptrXitp trans, shared_ptr<XscProtoPdu> pdu /* 入栈报文. */); /* 一个被动型事务开始. */
	void transPassFinished(SptrXitp trans, shared_ptr<XscProtoPdu> pdu /* 出栈报文. */); /* 一个被动型事务结束. */
	void transInitUni(SptrXitui trans, shared_ptr<XscProtoPdu> pdu /* 出栈报文. */); /* 一个主动型unidirection事务开始/结束. */
	void transPassUni(SptrXitup trans, shared_ptr<XscProtoPdu> pdu /* 入栈报文. */); /* 一个被动型unidirection事务开始/结束. */
public:
	XmsgHttpLog();
	virtual ~XmsgHttpLog();
};

#endif /* XMSGHTTPLOG_H_ */
