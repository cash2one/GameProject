﻿#ifndef _PLAYER_OBJECT_H_
#define _PLAYER_OBJECT_H_
#include "CharObject.h"

class CPlayerObject : public CCharObject, public ICommandHandler
{
public:
	CPlayerObject();

	~CPlayerObject();
public:
	virtual BOOL	IsChanged();

	virtual BOOL	ClearChangeFlag();

	virtual UINT32	WriteToBuffer(CBufferHelper *pBufHelper, UINT32 dwChangeFlag, UINT32 dwDest);

	virtual UINT32  ReadFromBuffer(CBufferHelper *pBufHelper, UINT32 dwChangeFlag);

public:
	BOOL			OnCommandHandle(UINT16 wCommandID, UINT64 u64ConnID, CBufferHelper *pBufferHelper);

	BOOL			OnUpdate(UINT32 dwTick);

	UINT64			GetConnectID();

	VOID			SetConnectID(UINT64 u64ConnID);

public:
	UINT32			LoadFromDBPacket(CBufferHelper *pBufferHelper);

public:
	UINT32			m_dwFeature; //玩家特征属性

public:
	UINT64			m_u64ConnID; //对应的连接ID
};



class CPlayerObjectMgr : public std::map<UINT64, CPlayerObject*>
{
public:
	CPlayerObjectMgr()
	{

	}

	~CPlayerObjectMgr()
	{

	}


public:
	BOOL			AddPlayer(CPlayerObject *pObject);

	BOOL			RemovePlayer(UINT64 ObjectID);

	CPlayerObject*	GetPlayer(UINT64 ObjectID);
};

class CUpdateObjectMgr : public std::set<CWorldObject*>
{
public:
	CUpdateObjectMgr()
	{

	}

	~CUpdateObjectMgr()
	{

	}


public:
	BOOL AddUpdateObject(CWorldObject *pObject);

	BOOL RemoveUpdateObject(CWorldObject *pObject);

	CWorldObject* GetFisrtOjbect();
};

#endif //_PLAYER_OBJECT_H_
