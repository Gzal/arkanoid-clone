#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

int window_width{ 800 }, window_height{ 600 };
float ballRadius{ 10.f };

struct Ball {
	CircleShape shape;

	Ball(float mX, float mY) {
		shape.setPosition(mX, mY);
		shape.setRadius(ballRadius);
		shape.setFillColor(Color::Red);
		shape.setOrigin(ballRadius, ballRadius);
	}
};

int main() {
	Ball ball(800 / 2, 600 / 2);

	RenderWindow window({ 800, 600 }, "Arkanoid - 2");
	window.setFramerateLimit(60);

	while (true) {
		window.clear(Color::Black);

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
			break;

		window.draw(ball.shape);
		window.display();
	}

	return 0;
}