//
//  baseMessageLayer.cpp
//  LastSupper
//
//  Created by Kohei on 2015/07/12.
//
//

#include "baseMessageLayer.h"

// コンストラクタ
baseMessageLayer::baseMessageLayer():
eventListener(nullptr),
frame(nullptr),
message(nullptr),
letterActions{},
pages{},
fontPath("fonts/cinecaption2.28.ttf"),
span(0.05f),
fontSize(24),
v_alignment(TextVAlignment::TOP),
h_alignment(TextHAlignment::LEFT),
m_position(Point::ZERO),
callback([](){}),
_isAllLetterDisplayed(false),
_isAllPageDisplayed(false)
{
	FUNCLOG
	// イベントリスナ生成
	this->eventListener = EventListenerKeyboard::create();
	this->eventListener->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event* event){if(keyCode == EventKeyboard::KeyCode::KEY_SPACE) this->onSpacePressed();};
	
	// イベントリスナ登録
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(this->eventListener, this);
}

// デストラクタ
baseMessageLayer::~baseMessageLayer()
{FUNCLOG}

// create関数（子クラスで呼び出す用）
baseMessageLayer* baseMessageLayer::create(const queue<string>& pages)
{
	baseMessageLayer* pRet = new(nothrow)baseMessageLayer();
	if (pRet && pRet->init())
	{
		// オブジェクトを自動メモリ管理へ登録
		pRet->autorelease();
		// ページをセット
		pRet->setPages(pages);
		return pRet;
	}
	CC_SAFE_DELETE(pRet);
	return nullptr;
}

// spaceキーを押した時の処理
void baseMessageLayer::onSpacePressed()
{
	// すべてのページを表示し終えていた場合
	if(this->_isAllPageDisplayed){
		this->end();
		return;
	}
	// ページ内ですべての文字を表示し終えていたら、次ページへ
	if(this->_isAllLetterDisplayed){
		this->popPage();
	}else
	{
		// 表示できていなければ、全表示
		for(Action* letterAction : this->letterActions)
		{this->stopAction(letterAction);}
		for(int i = 0; i < this->message->getStringLength(); i++)
		{Sprite* letter = this->message->getLetter(i); if(letter) letter->setVisible(true);}
		this->_isAllLetterDisplayed = true;
		this->allLetterDisplayed();
		if(this->pages.size() == 1) this->_isAllPageDisplayed = true;
	}
	return;
}

// 表示を開始する
void baseMessageLayer::start()
{this->display();}

// ページ開始時に呼ばれるメソッド、メッセージの流れ方以外を変えたい場合はこちらをオーバーライドすべし
void baseMessageLayer::display()
{this->displayMessage();}

// メッセージを表示
void baseMessageLayer::displayMessage()
{
	FUNCLOG
	this->message = Label::createWithTTF(this->pages.front(), this->fontPath, this->fontSize);
	this->message->setPosition(this->m_position);
	this->message->setHorizontalAlignment(this->h_alignment);
	this->message->setVerticalAlignment(this->v_alignment);
	this->frame->addChild(this->message);
	
	int stringLength = this->message->getStringLength();
	int lastLetterIndex = 0;
	// 改行文字をカウントしない最後の文字のインデックスを取得する
	for(int i = stringLength - 1; i >= 0; i--)
	{
		Sprite* letter = this->message->getLetter(i);
		if(letter){
			lastLetterIndex = i;
			break;
		}
	}

	// アニメーション設定
	for(int i = 0; i < stringLength; i++)
	{
		Sprite* letter = this->message->getLetter(i);
		// エスケープ文字をスルー
		if(letter)
		{
			letter->setVisible(false);
			Sequence* letterAction = Sequence::create(DelayTime::create(this->span * i), TargetedAction::create(letter, Show::create()), CallFunc::create([=](){if(i == lastLetterIndex){this->_isAllLetterDisplayed = true;this->allLetterDisplayed(); if(this->pages.size() == 1) this->_isAllPageDisplayed = true;}}), nullptr);
			this->letterActions.push_back(letterAction);
			this->runAction(letterAction);
		}
	}
	return;
}

// 改ページを行う
void baseMessageLayer::popPage()
{
	FUNCLOG
	this->pages.pop();
	this->message->setVisible(false);
	this->removeChild(this->message);
	this->display();
	return;
}

// メッセージを終了する
void baseMessageLayer::end()
{
	FUNCLOG
	this->setCascadeOpacityEnabled(true);
	this->eventListener->setEnabled(false);
	this->runAction(Sequence::createWithTwoActions(TargetedAction::create(this, FadeOut::create(0.2f)), CallFunc::create([=](){this->setVisible(false); this->removeFromParent();})));
	this->callback();
}

// そのページでの文字がすべて表示された時に実行される
void baseMessageLayer::allLetterDisplayed()
{}

// 使用するフォントファイルのパスをセット
void baseMessageLayer::setFontFilePath(const string& fontPath)
{this->fontPath = fontPath;}

// 表示するフォントのサイズをセット
void baseMessageLayer::setFontSize(const int& fontSize)
{this->fontSize = fontSize;}

// 縦方向の位置をセット
void baseMessageLayer::setVAlignment(const TextVAlignment& v_alignment)
{this->v_alignment = v_alignment;}

// 横方向の位置をセット
void baseMessageLayer::setHAlignment(const TextHAlignment& h_alignment)
{this->h_alignment = h_alignment;}

// 文字表示の間隔をセット
void baseMessageLayer::setSpan(const float& span)
{this->span = span;}

// ページ群をセット
void baseMessageLayer::setPages(const queue<string>& pages)
{this->pages = pages;}

// ページを追加
void baseMessageLayer::addPage(const string& page)
{this->pages.push(page);}

// メッセージレイヤーの枠をセット
void baseMessageLayer::setFrame(Sprite* frame)
{this->frame = frame;}

// メッセージをすべて見終わった際に実行されるメソッドをセット
void baseMessageLayer::setCallback(const function<void()>& callback)
{this->callback = callback;}

// メッセージの座標をセット
void baseMessageLayer::setMessagePosition(const Point& m_position)
{this->m_position = m_position;}