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

        // Clear the window
        sfRenderWindow_clear(window, sfBlack);

        // Draw your elements
        sfRenderWindow_drawSprite(window, bg_sprite, NULL);

        // Display everything your drawn in the window
        sfRenderWindow_display(window);
    }
    return (0);
}