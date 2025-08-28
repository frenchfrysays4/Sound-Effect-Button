#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		// Log to the console/log mod is starting up
		log::info("Starting up...");

		// Creating the button (log)
		log::debug("Creating the button...");
		auto spr = CCSprite::createWithSpriteFrameName("GJ_musicOnBtn_001.png");
		auto btn = CCMenuItemSpriteExtra::create(
			spr,
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);
		log::debug("Button creation completed successfully");

		// Declare menu and add a child
		auto menu = this->getChildByID("bottom-menu");
		if (menu) {
			menu->addChild(btn);
			log::debug("Added the button to the menu");
			// Add an ID to the button
			btn->setID("sound-effect-button");
			// Update the menu so that it shows in-game
			menu->updateLayout();
			log::debug("Updated layout of the menu so that the button shows");
		} else {
			log::error("Menu 'bottom-menu' not found!");
			FLAlertLayer::create(
				"Error",
				"Menu 'bottom-menu' not found! The button will not be added.",
				"OK"
			)->show();
			return true;
		}

		return true;
	}

	void onMyButton(CCObject*) {
		FLAlertLayer::create(
			"Clicked!",
			"I have played a <cj>Sound Effect</c>!",
			"OK"
		)->show();
		log::debug("Showed popup");

		static int sound = 0;

		if (sound == 0) {
			FMODAudioEngine::sharedEngine()->playEffect("among-us-role-reveal-sound.mp3"_spr);
			log::info("Played Sound effect among us role reveal");
		} else if (sound == 1) {
			FMODAudioEngine::sharedEngine()->playEffect("error.mp3"_spr);
			log::info("Played sound efffect error");
		} else if (sound == 2) {
			FMODAudioEngine::sharedEngine()->playEffect("metal-pipe-clang.mp3"_spr);
			log::info("Played sound effect metal pipe clang");
		} else if (sound == 3) {
			FMODAudioEngine::sharedEngine()->playEffect("roblox-sword.mp3"_spr);
			log::info("Played sound effect Roblox sword");
		} else if (sound == 4) {
			FMODAudioEngine::sharedEngine()->playEffect("vine-boom.mp3"_spr);
			log::info("Played sound effect vine boom");
		}

		sound = sound + 1;

		if (sound == 5) sound = 0;
	}
};
