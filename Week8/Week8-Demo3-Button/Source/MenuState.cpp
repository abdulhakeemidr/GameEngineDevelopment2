#include <MenuState.hpp>
#include <Utility.hpp>
#include <ResourceHolder.hpp>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <Label.hpp>

#pragma region step 5
#include <Button.hpp>
#pragma endregion


MenuState::MenuState(StateStack& stack, Context context)
	: State(stack, context)
	, mOptions()
	, mOptionIndex(0)
	, mGUIContainer()
{
	/*auto demoLabel = std::make_shared<GUI::Label>(
		"This is a GUI Button demonstration", *getContext().fonts);
	demoLabel->setPosition(context.window->getView().getSize().x / 2.f, 10.f);
	centerOrigin(demoLabel->getText());
	demoLabel->getText().setFillColor(sf::Color::Black);
	mGUIContainer.pack(demoLabel);*/

	sf::Texture& texture = context.textures->get(Textures::TitleScreen);
	//sf::Font& font = context.fonts->get(Fonts::Main);

	mBackgroundSprite.setTexture(texture);

#pragma region step 6

	auto playButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	playButton->setPosition(100, 250);
	playButton->setText("Play");
	playButton->setCallback([this]()
	{
		requestStackPop();
		requestStackPush(States::Game);
	});


	auto exitButton = std::make_shared<GUI::Button>(*context.fonts, *context.textures);
	exitButton->setPosition(100, 350);
	exitButton->setText("Exit");
	exitButton->setCallback([this]()
	{
		requestStackPop();
	});

	mGUIContainer.pack(playButton);
	mGUIContainer.pack(exitButton);

	// A simple menu demonstration
	//sf::Text playOption;
	//playOption.setFont(font);
	//playOption.setString("Play");
	//centerOrigin(playOption);
	//playOption.setPosition(context.window->getView().getSize() / 2.f);
	//mOptions.push_back(playOption);

	//sf::Text exitOption;
	//exitOption.setFont(font);
	//exitOption.setString("Exit");
	//centerOrigin(exitOption);
	//exitOption.setPosition(playOption.getPosition() + sf::Vector2f(0.f, 30.f));
	//mOptions.push_back(exitOption);

	//updateOptionText();

#pragma endregion
}


bool MenuState::handleEvent(const sf::Event& event)
{
	mGUIContainer.handleEvent(event);
	return false;

#pragma region step 9
	//// The demonstration menu logic
	//if (event.type != sf::Event::KeyPressed)
	//	return false;

	//if (event.key.code == sf::Keyboard::Return)
	//{
	//	if (mOptionIndex == Play)
	//	{
	//		requestStackPop();
	//		requestStackPush(States::Game);
	//		requestStackPush(States::Loading);
	//	}
	//	else if (mOptionIndex == Exit)
	//	{
	//		// The exit option was chosen, by removing itself, the stack will be empty, and the game will know it is time to close.
	//		requestStackPop();
	//	}
	//}

	//else if (event.key.code == sf::Keyboard::Up)
	//{
	//	// Decrement and wrap-around
	//	if (mOptionIndex > 0)
	//		mOptionIndex--;
	//	else
	//		mOptionIndex = mOptions.size() - 1;

	//	updateOptionText();
	//}

	//else if (event.key.code == sf::Keyboard::Down)
	//{
	//	// Increment and wrap-around
	//	if (mOptionIndex < mOptions.size() - 1)
	//		mOptionIndex++;
	//	else
	//		mOptionIndex = 0;

	//	updateOptionText();
	//}

#pragma endregion
}


bool MenuState::update(sf::Time)
{
	return true;
}

#pragma region step 8

//void MenuState::updateOptionText()
//{
//	if (mOptions.empty())
//		return;
//
//	// White all texts
//	for (sf::Text& text : mOptions)
//		text.setFillColor(sf::Color::White);
//
//	// Red the selected text
//	mOptions[mOptionIndex].setFillColor(sf::Color::Red);
//}
#pragma endregion

void MenuState::draw()
{
	sf::RenderWindow& window = *getContext().window;

	window.setView(window.getDefaultView());
	window.draw(mBackgroundSprite);

	/*for (const sf::Text& text : mOptions)
		window.draw(text);*/

	window.draw(mGUIContainer);
}
