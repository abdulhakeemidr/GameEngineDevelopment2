#include <SFML\Graphics.hpp>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}

//const float Game::PlayerSpeed = 100.f;
//const sf::Time Game::TimePerFrame = sf::seconds(1.f/ 60.f);
//
//Game::Game()
//	: mWindow(sf::VideoMode(800, 600), "My OOP Template", sf::Style::Close)
//	, mPlayer()
//	, mPlayerTexture()
//	, mBackground()
//	, mBackgroundTexture()
//	, mStatisticsText()
//	, mStatisticUpdateTime()
//	, mStatisticsNumFrames()
//	, mIsMovingDown(false)
//	, mIsMovingLeft(false)
//	, mIsMovingRight(false)
//	, mIsMovingUp(false)
//
//{
//	if (!mIcon.loadFromFile("Media/Textures/icon.png"))
//	{
//		cout << "cannot find Media/Textures/icon.png" << endl;
//	}
//
//	mWindow.setIcon(mIcon.getSize().x, mIcon.getSize().y, mIcon.getPixelsPtr());
//
//	if (!isBackgroundTexture.loadFromFile("Media/Textures/cute_image.jpg"))
//	{
//		cout << "cannot find Media/Textures/cute_image.jpg" << endl;
//		return;
//	}
//
//	mPlayer.setTexture(mPlayerTexture);
//
//	if (!mFont.loadFromFile("Media/Sansation.tff"))
//	{
//
//	}
//}
//
//Game::run()
//{
//	sf::Clock clock;
//	sf::timeSinceLastUpdate = sf::Time::Zero;
//
//	while (mWindow.isOpen())
//	{
//		sf::Time elapsedTime = clock.restart();
//		timeSinceLastUpdate += elapsedTime;
//
//		while (timeSinceLastUpdate > TimePerFrame)
//		{
//			processEvents();
//			update();
//			render();
//		}
//	}
//}
//
//void Game::processEvents()
//{
//}
//
//void Game::update()
//{
//}
//
//void Game::render()
//{
//}
//
//void Game::updateStatistics(sf::Time elapsedTime)
//{
//}
//
//void Game::handlePlayerInput(sf::Keyboard::Key, bool isPressed)
//{
//}
