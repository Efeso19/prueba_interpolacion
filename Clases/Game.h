
#ifndef __GAME_H__
#define __GAME_H__

#include <iostream>
#include "../Includes/ResourceHolder.hpp"
#include <SFML/Graphics.hpp>

// ID's para cargar texturas (usar con Textures::ID)
namespace Textures
{
	enum ID
	{
		Plane
	};
}

// ID's para cargar fuentes (usar con Fonts::ID)
namespace Fonts
{
	enum ID
	{
		OpenSans
	};
}




class Game : private sf::NonCopyable
{
public:
    Game();
    void			run();
    
    
private:
    void			processEvents();  // Captura y procesa eventos
    void			update(sf::Time elapsedTime);
    void			render();
    
    void			updateStatistics(sf::Time elapsedTime);
    void			handlePlayerInput(sf::Keyboard::Key key, bool isPressed);  // Maneja eventos
    
    
private:
    static const float		velPlayer;
    static const float          angPlayer;
    static const sf::Time	timePerFrame;
    
    //Recursos
    ResourceHolder<sf::Texture, Textures::ID>	contTextures;
    ResourceHolder<sf::Font, Fonts::ID>		contFonts;
    
    //Graficos
    sf::RenderWindow		window;
    sf::Sprite			sprite;
    
    //Estadisticas
    sf::Text			mStatisticsText;
    sf::Time			mStatisticsUpdateTime;
    std::size_t			mStatisticsNumFrames;
    
    //Eventos
    bool			isMovingUp;
    bool			isMovingDown;
    bool			isMovingRight;
    bool			isMovingLeft;
    bool                        mIsRotatingLeft;
    bool                        mIsRotatingRight;
	bool			firstTime;
};



#endif


