#include <SFML/Graphics.hpp>

struct Point
{
	private:
		bool Cartesian = true;
		bool Screen = false;
	public:	
		int ScreenHeight = 600;
		int PosX = 50;
		int PosY = 50;
		void Convert()  // Convert Cartesian Coordinate to Screen Coordinate, and Vice Versa
		{
			PosY = ScreenHeight - PosY;
			Cartesian = !Cartesian;
			Screen = !Screen;
		}
		bool isCartesian()
		{
			return Cartesian;
		}
		bool isScreen()
		{
			return Screen;
		}
};

Point Object;

bool runEventHandler(int ScreenHeight)
{
	bool ReturnInfo = false;
	if(Object.isCartesian())
	{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			// Do stuff for when W is pressed
			Object.PosY += 2;
			ReturnInfo = true;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			// Do stuff for when A is pressed
			Object.PosX -= 2;
			ReturnInfo = true;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			// Do stuff for when S is pressed
			Object.PosY -= 2;
			ReturnInfo = true;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			// Do stuff for when D is pressed
			Object.PosX += 2;
			ReturnInfo = true;
		}
		
		Object.Convert();
	}
	else if(Object.isScreen())
	{
		Object.Convert();
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			// Do stuff for when W is pressed
			Object.PosY += 2;
			ReturnInfo = true;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			// Do stuff for when A is pressed
			Object.PosX -= 2;
			ReturnInfo = true;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			// Do stuff for when S is pressed
			Object.PosY -= 2;
			ReturnInfo = true;
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			// Do stuff for when D is pressed
			Object.PosX += 2;
			ReturnInfo = true;
		}
		
		Object.Convert();
	}
	
	return ReturnInfo;
}


namespace Writer
{
	sf::Font font;
	sf::Text Typewriter;
	
	
	void InitializeWriter()
	{
		//Loading Font
		if (!font.loadFromFile("arial.ttf")){/*Error*/}
	
		//Loading Typewriter
		Typewriter.setFont(font);
		Typewriter.setString("Pirel Ganteng");
		Typewriter.setCharacterSize(45);
		Typewriter.setFillColor(sf::Color::Green);
	}
};



int main()
{	
	// Start the Typewriter implmentation
	Writer::InitializeWriter();

	//Load Image as Textures
	sf::Texture bitmap;
	bitmap.loadFromFile("Asset1.png");
	
	//Create A Sprite
	sf::Sprite sprite;
	sprite.setTexture(bitmap);
	sprite.setTextureRect(sf::Rect<int>(0, 0, 100, 100));   // You can also use sf::intRect(0, 0, 100, 100), for it is a typedf simplification on the sfml part
	sprite.setColor(sf::Color(255, 255, 0, 255));
	sprite.setPosition(100, 100);
	
    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 750), "Schizo Pirel Suite");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
		
		
		// Move the sprite according to WASD input
		runEventHandler(750);
		sprite.setPosition(Object.PosX, Object.PosY);
		

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(sprite);

        // end the current frame
        window.display();
    }

    return 0;
}



