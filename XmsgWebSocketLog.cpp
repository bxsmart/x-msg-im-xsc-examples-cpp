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
 * XmsgWebSocketLog.cpp
 *
 *  Created on: 2019年11月6日 下午8:12:59
 *      Author: xzwdev
 */

#include "XmsgWebSocketLog.h"

XmsgWebSocketLog::XmsgWebSocketLog()
{

}

/* 定时器振荡, 仅在主线程上. */
void XmsgWebSocketLog::didaMainThread(ullong now)
{

}

/* 定时器振荡, 需要注意是, 此函数会在每个XscTcpWorker线程上都触发一次. 因此, 在此函数中操作ThreadLocal变量是安全的. */
void XmsgWebSocketLog::dida(ullong now)
{

}

/* XscTcpChannel上的入栈消息. */
void XmsgWebSocketLog::rx(XscChannel* channel, uchar* dat, int len)
{

}

/* XscTcpChannel上的出栈消息. */
void XmsgWebSocketLog::tx(XscChannel* channel, uchar* dat, int len)
{

}

/* 一个主动型事务开始. */
void XmsgWebSocketLog::transInitStart(SptrXiti trans, shared_ptr<XscProtoPdu> pdu /* 出栈报文. */)
{

}

/* 一个主动型事务结束. */
void XmsgWebSocketLog::transInitFinished(SptrXiti trans, shared_ptr<XscProtoPdu> pdu /* 入栈报文(可能为空). */)
{

}

/* 一个被动型事务开始. */
void XmsgWebSocketLog::transPassStart(SptrXitp trans, shared_ptr<XscProtoPdu> pdu /* 入栈报文. */)
{

}

/* 一个被动型事务结束. */
void XmsgWebSocketLog::transPassFinished(SptrXitp trans, shared_ptr<XscProtoPdu> pdu /* 出栈报文(可能为空). */)
{

}

/* 一个主动型unidirection事务开始/结束. */
void XmsgWebSocketLog::transInitUni(SptrXitui trans, shared_ptr<XscProtoPdu> pdu /* 出栈报文. */)
{

}

/* 一个被动型unidirection事务开始/结束. */
void XmsgWebSocketLog::transPassUni(SptrXitup trans, shared_ptr<XscProtoPdu> pdu /* 入栈报文. */)
{

}

XmsgWebSocketLog::~XmsgWebSocketLog()
{

}

