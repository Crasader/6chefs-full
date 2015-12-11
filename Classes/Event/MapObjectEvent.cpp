//
//  MapObjectEvent.cpp
//  LastSupper
//
//  Created by Kohei on 2015/10/25.
//
//

#include "MapObjectEvent.h"

#include "Event/EventScriptValidator.h"
#include "Event/EventScriptMember.h"

#include "MapObjects/MapObject.h"
#include "MapObjects/MapObjectList.h"
#include "Mapobjects/Party.h"

#include "Managers/DungeonSceneManager.h"

#pragma mark MapObjectEvent

bool MapObjectEvent::init(rapidjson::Value& json)
{
    if(!GameEvent::init()) return false;
    
    // オブジェクトのIDを保持
    if (!this->validator->hasMember(json, member::OBJECT_ID)) return false;
    
    this->objectId = json[member::OBJECT_ID].GetString();
    
    return true;
}

#pragma mark -
#pragma mark ReactionEvent

bool ReactionEvent::init(rapidjson::Value& json)
{
    if(!MapObjectEvent::init(json)) return false;
    
    return true;
}

void ReactionEvent::run()
{
    MapObject* target {this->validator->getMapObjectById(this->objectId)};
    
    if(!target)
    {
        this->setDone();
        
        return;
    }
    
    Sprite* icon {Sprite::createWithSpriteFrameName("icon_sign.png")};
    icon->setPosition(Point(0, target->getContentSize().height / 2));
    icon->setGlobalZOrder(Priority::CHARACTER_MESSAGE);
    icon->setScaleY(0.01f);
    icon->setAnchorPoint(Point::ANCHOR_MIDDLE_BOTTOM);
    target->addChild(icon);
    
    SoundManager::getInstance()->playSE("reaction.mp3");
    icon->runAction(Sequence::create(EaseElasticOut::create(ScaleTo::create(0.6f, 1.f), 0.5f), DelayTime::create(1.f), RemoveSelf::create(), CallFunc::create([this](){this->setDone();}), nullptr));
}

#pragma mark -
#pragma mark CreateMapObjectEvent

bool CreateMapObjectEvent::init(rapidjson::Value& json)
{
    if(!MapObjectEvent::init(json)) return false;
 
    return true;
}

void CreateMapObjectEvent::run()
{
    MapObject* target {this->validator->getMapObjectById(this->objectId, false)};
    
    if(!target)
    {
        this->setDone();
        
        return;
    }

    DungeonSceneManager::getInstance()->addMapObject(target);
    this->setDone();
}

#pragma mark -
#pragma mark RemoveMapObjectEvent

bool RemoveMapObjectEvent::init(rapidjson::Value& json)
{
    if(!MapObjectEvent::init(json)) return false;
    
    return true;
}

void RemoveMapObjectEvent::run()
{
    this->setDone();
    DungeonSceneManager::getInstance()->getMapObjectList()->removeById(stoi(this->objectId));
}

#pragma mark -
#pragma mark FollowCharacterEvent

bool FollowCharacterEvent::init(rapidjson::Value& json)
{
    if(!MapObjectEvent::init(json)) return false;
    
    return true;
}

void FollowCharacterEvent::run()
{
    this->setDone();
    MapObject* follower {this->validator->getMapObjectById(this->objectId)};
    DungeonSceneManager::getInstance()->getParty()->addMember(static_cast<Character*>(follower));
}

#pragma mark -
#pragma mark ReleaseFollowingCharacterEvent

bool ReleaseFollowingCharacterEvent::init(rapidjson::Value& json)
{
    if(!MapObjectEvent::init(json)) return false;
    
    return true;
}

void ReleaseFollowingCharacterEvent::run()
{
    this->setDone();
    DungeonSceneManager::getInstance()->getParty()->removeMember(stoi(this->objectId));
}

#pragma mark -
#pragma mark 

bool WarpMapObjectEvent::init(rapidjson::Value& json)
{
    if(!MapObjectEvent::init(json)) return false;
    
    if(!this->validator->hasMember(json, member::X)) return false;
    if(!this->validator->hasMember(json, member::Y)) return false;
    if(!this->validator->hasMember(json, member::DIRECTION)) return false;
    this->point = Point(json[member::X].GetInt(), json[member::Y].GetInt());
    this->direction = this->validator->getDirection(json);
    
    return true;
}

void WarpMapObjectEvent::run()
{
    this->setDone();
    MapObject* target = DungeonSceneManager::getInstance()->getMapObjectList()->getMapObject(stoi(this->objectId));
    target->setGridPosition(this->point);
    target->setDirection(this->direction);
    DungeonSceneManager::getInstance()->setMapObjectPosition(target);
}