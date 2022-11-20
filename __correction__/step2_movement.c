/*
** EPITECH PROJECT, 2022
** sfml
** File description:
** main
*/

#include "my.h"

int main(void)
{
    // CSFML Window mandatory variables in order to run a window
    sfVideoMode mode = {1600, 800, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "SFML !", sfClose | sfResize, NULL);
    sfEvent event;

    // Your code goes here (creating new textures, sprites, music, songs...)
    sfSprite *bg_sprite = sfSprite_create();
    sfTexture *bg_texture = sfTexture_createFromFile("./assets/sprites/sky_blue.jpg", NULL);
    sfSprite_setTexture(bg_sprite, bg_texture, sfFalse);

    // Duck
    sfIntRect duck_sprite_rect =  {0, 0, 170, 165};
    sfVector2f duck_position = {0, 0};
    sfSprite *duck_sprite = sfSprite_create();
    sfTexture *duck_texture = sfTexture_createFromFile("./assets/sprites/duck_blue.png", NULL);
    sfSprite_setTexture(duck_sprite, duck_texture, sfTrue);
    sfSprite_setTextureRect(duck_sprite, duck_sprite_rect);
    sfClock *duck_animation_clock = sfClock_create();
    unsigned int duck_animation_time = 0;

    sfClock *duck_movement_clock = sfClock_create();
    unsigned int duck_movement_time = 0;

    while (sfRenderWindow_isOpen(window)) {

        // Check for events (and EVENTs only) happening in your window
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }

            // Use ESCAPE to exit - Don't waste time reaching to the red cross (use for debug)
            if (sfKeyboard_isKeyPressed(sfKeyEscape))
                sfRenderWindow_close(window);
        }

        // Update your elements (buttons, clocks, animations...)
        duck_animation_time = sfTime_asMilliseconds(sfClock_getElapsedTime(duck_animation_clock));
        if (duck_animation_time >= 100) {
            if (duck_sprite_rect.left >= 340) {
                duck_sprite_rect.left = 0;
            } else {
                duck_sprite_rect.left += 170;
            }
            sfSprite_setTextureRect(duck_sprite, duck_sprite_rect);
            sfClock_restart(duck_animation_clock);
        }

        duck_movement_time = sfTime_asMilliseconds(sfClock_getElapsedTime(duck_movement_clock));
        if (duck_movement_time >= 10) {
            duck_position.x += 5;
            sfSprite_setPosition(duck_sprite, duck_position);
            sfClock_restart(duck_movement_clock);
        }

        // Clear the window
        sfRenderWindow_clear(window, sfBlack);

        // Draw your elements
        sfRenderWindow_drawSprite(window, bg_sprite, NULL);
        sfRenderWindow_drawSprite(window, duck_sprite, NULL);

        // Display everything your drawn in the window
        sfRenderWindow_display(window);
    }
    return (0);
}