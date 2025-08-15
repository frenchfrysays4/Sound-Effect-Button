#include <Geode/Geode.hpp>

using namespace geode::prelude;

#include <Geode/modify/MenuLayer.hpp>
class $modify(MyMenuLayer, MenuLayer) {
	bool init() {
		if (!MenuLayer::init()) {
			return false;
		}

		// Log to the console/log mod is starting up
		log::info("Starting up...");

		// Creating the button (log)
		log::debug("Creating the button...");
		auto spr = ButtonSprite::create("Click Me!");
		auto btn = CCMenuItemSpriteExtra::create(
			spr,
			this,
			menu_selector(MyMenuLayer::onMyButton)
		);
		log::debug("Button creation completed successfully");

		// Declare menu and add a child
		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(btn);

		// Added an ID the the button
		btn->setID("sound-effect-button"_spr);

		// Update the menu so that it shows in-game
		menu->updateLayout();

		return true;
	}

	void onMyButton(CCSprite*) {

	}
};