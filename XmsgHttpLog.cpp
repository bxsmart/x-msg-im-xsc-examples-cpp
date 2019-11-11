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
 * XmsgHttpLog.cpp
 *
 *  Created on: 2019年11月6日 下午5:42:05
 *      Author: xzwdev
 */

#include "XmsgHttpLog.h"

XmsgHttpLog::XmsgHttpLog()
{

}

/* 当连接到来时, 构造一个n2h方向的XscHttpChannel的子类. */
shared_ptr<XscHttpChannel> XmsgHttpLog::newXscHttpChannel(shared_ptr<XscHttpWorker> wk, int cfd, const string& peer)
{
	return shared_ptr<XmsgImHttpChannel>(new XmsgImHttpChannel(wk, wk->mtu, cfd, peer));
}

/* 定时器振荡, 仅在主线程上. */
void XmsgHttpLog::didaMainThread(ullong now)
{

}

/* 定时器振荡, 需要注意是, 此函数会在每个XscHttpWorker线程上都触发一次. 因此, 在此函数中操作ThreadLocal变量是安全的. */
void XmsgHttpLog::dida(ullong now)
{

}

/* XscTcpChannel上的入栈消息. */
void XmsgHttpLog::rx(XscChannel* channel, uchar* dat, int len)
{

}

/* XscTcpChannel上的出栈消息. */
void XmsgHttpLog::tx(XscChannel* channel, uchar* dat, int len)
{

}

/* 一个主动型事务开始. */
void XmsgHttpLog::transInitStart(SptrXiti trans, shared_ptr<XscProtoPdu> pdu /* 出栈报文. */)
{

}

/* 一个主动型事务结束. */
void XmsgHttpLog::transInitFinished(SptrXiti trans, shared_ptr<XscProtoPdu> pdu /* 入栈报文(可能为空). */)
{

}

/* 一个被动型事务开始. */
void XmsgHttpLog::transPassStart(SptrXitp trans, shared_ptr<XscProtoPdu> pdu /* 入栈报文. */)
{

}

/* 一个被动型事务结束. */
void XmsgHttpLog::transPassFinished(SptrXitp trans, shared_ptr<XscProtoPdu> pdu /* 出栈报文. */)
{

}

/* 一个主动型unidirection事务开始/结束. */
void XmsgHttpLog::transInitUni(SptrXitui trans, shared_ptr<XscProtoPdu> pdu /* 出栈报文. */)
{

}

/* 一个被动型unidirection事务开始/结束. */
void XmsgHttpLog::transPassUni(SptrXitup trans, shared_ptr<XscProtoPdu> pdu /* 入栈报文. */)
{

}

XmsgHttpLog::~XmsgHttpLog()
{

}
