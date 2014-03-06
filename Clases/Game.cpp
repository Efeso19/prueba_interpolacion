#include "Game.h"


/************ VARIABLES GLOBALES ************/

const float Game::velPlayer = 180.f;
const float Game::angPlayer = 140.f;
const sf::Time Game::timePerFrame = sf::seconds(1000.f/15.f);
const int ancho = 640, alto = 480;
const float segStatistics = 0.5f; //segundos de refresco de las estadisticas




/************ CONSTRUCTOR **************/
Game::Game()
: window(sf::VideoMode(ancho, alto, 24), "TITULO APLICACION", sf::Style::Close)
, contFonts()
, contTextures()
, sprite()
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
, isMovingUp(false)
, isMovingDown(false)
, isMovingRight(false)
, isMovingLeft(false)
, mIsRotatingLeft(false)
, mIsRotatingRight(false)
, firstTime(true)
{
	window.setVerticalSyncEnabled(true); //Para evitar cortes en los refrescos
	window.setFramerateLimit(125);	//Establecemos maximo real de procesamiento (aunque trabajamos con 60)
	

   // Cargamos RECURSOS. Utilizamos los contenedores genericos
	try{
		contTextures.load(Textures::Plane, "Recursos/Eagle.png");
		contFonts.load(Fonts::OpenSans, "Recursos/OpenSans-Regular.ttf");
	}
	catch (std::runtime_error& e)	{
		std::cout << "Exception: " << e.what() << std::endl;
		exit(0);
	}
    
	
   //Configuramos Items
	sprite.setTexture(contTextures.get(Textures::Plane));       //Iniciamos el sprite con la imagen
	sprite.setPosition(100.f, 100.f);
	
	//Centramos el Eje de Rotacion del Sprite (así conseguimos una rotación centrada)
	sprite.setOrigin(sprite.getLocalBounds().width/2, sprite.getLocalBounds().height/2);
	
	mStatisticsText.setFont(contFonts.get(Fonts::OpenSans));
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(13);
}



/**************  METODOS PRINCIPALES **************/

void Game::run()    //Metodo principal
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;  //Tiempo desde el ultimo cambio de frame
	
	
	while (window.isOpen())
	{
		sf::Time elapsedTime = clock.restart();     //Actualizamos variables de tiempo
		timeSinceLastUpdate += elapsedTime;
        
		processEvents();
		
        //Llevamos control en las actualizaciones por frame
		while (timeSinceLastUpdate > timePerFrame)   // 15 veces/segundo
		{
			timeSinceLastUpdate -= timePerFrame;
            
            //Realizamos actualizaciones
			update(timePerFrame);            
		}
        
		updateStatistics(elapsedTime);  //Actualización de pantalla a tiempo de ejecución
        render();
	}
}



/***************  METODOS DE FISICA Y DISPLAY  *************/

void Game::update(sf::Time elapsedTime)     //Actualiza la fisica
{
	if(!firstTime)
	{
		//Variables auxiliares
		sf::Vector2f movement(0.f, 0.f);
		sf::Vector2f posicion = sprite.getPosition();
		sf::Vector2f origin = sprite.getOrigin();
		float ang = 0.f;

		// Actualizamos fisicas (posicion o rotacion)
		if (isMovingUp && (posicion.y - origin.y) > 0)
			movement.y -= velPlayer;
		if (isMovingDown && (posicion.y + origin.y) < alto)
			movement.y += velPlayer;
		if (isMovingLeft && (posicion.x - origin.x) > 0)
			movement.x -= velPlayer;
		if (isMovingRight && (posicion.x + origin.x) < ancho)
			movement.x += velPlayer;

		/*if(mIsRotatingLeft)
			ang -= angPlayer;
		if(mIsRotatingRight)
			ang += angPlayer;*/

		// Movemos y rotamos Sprite real
		sprite.move(movement * elapsedTime.asSeconds());
	   // sprite.rotate(ang * elapsedTime.asSeconds());
	}
	
	firstTime=false;
}

void Game::render()     //Dibuja
{
	window.clear();
	//window.draw(sprite);
	
	//LLAMAR AL DRAW DEL PLAYER
	
	window.draw(mStatisticsText);
	window.display();
}





/************** EVENTOS ****************/

void Game::processEvents()   //Captura y procesa eventos
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
                
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
                
			case sf::Event::Closed:
				window.close();
				break;
		}
	}
}

// Realiza las operaciones correspondientes a cada Evento
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Up)            //Traslaciones
		isMovingUp = isPressed;
	else if (key == sf::Keyboard::Down)
		isMovingDown = isPressed;
	else if (key == sf::Keyboard::Left)
		isMovingLeft = isPressed;
	else if (key == sf::Keyboard::Right)
		isMovingRight = isPressed;
    
    else if (key == sf::Keyboard::A)        //Rotaciones
        mIsRotatingLeft = isPressed;
    else if (key == sf::Keyboard::S)
        mIsRotatingRight = isPressed;
}
