Prueba Interpolación
====================

## Documentación

### Controles
Con las flechas se moverá el Player, y con la tecla "X" se podrá activar o desactivar la interpolación

### Estructura
Se ha estructurado en las siguientes clases:

* **Player**: Contiene un objeto PhsysicsState y Render, además de sus propios métodos Update y Draw
   * **PhsysicsState**: Se encarga de manejar las variables de la física del Player
   * **Render**: Se encarga de, según el estado de la física, realizar la actualización de la posición correspondiente al tiempo transcurrido desde el último refresco de pantalla, y dibujar el Sprite
