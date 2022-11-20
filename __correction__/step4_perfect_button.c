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

    // Play button
    sfIntRect play_button_sprite_rect =  {0, 0, 460, 110};
    sfVector2f play_button_position = {
        mode.width / 2 - play_button_sprite_rect.width / 2,
        mode.height / 2 - play_button_sprite_rect.height / 2
    };
    sfSprite *play_button_sprite = sfSprite_create();
    sfTexture *play_button_texture = sfTexture_createFromFile("./assets/sprites/buttons_main_menu.png", NULL);
    sfImage *play_button_image = sfTexture_copyToImage(play_button_texture);
    sfSprite_setTexture(play_button_sprite, play_button_texture, sfTrue);
    sfSprite_setTextureRect(play_button_sprite, play_button_sprite_rect);
    sfSprite_setPosition(play_button_sprite, play_button_position);

    // Mouse
    sfVector2i mouse_pos = {0, 0};

    while (sfRenderWindow_isOpen(window)) {
        mouse_pos = sfMouse_getPositionRenderWindow(window);

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

        sfFloatRect play_button_bounds = sfSprite_getGlobalBounds(play_button_sprite);
        sfColor color = sfImage_getPixel(play_button_image,
        (mouse_pos.x - play_button_position.x) + play_button_sprite_rect.left,
        (mouse_pos.y - play_button_position.y) + play_button_sprite_rect.top);
        if (sfFloatRect_contains(&play_button_bounds, mouse_pos.x, mouse_pos.y) && color.a != 0) {
            if (sfMouse_isButtonPressed(sfMouseLeft)) {
                play_button_sprite_rect.left = 920;
                duck_position.x = 0;
                // Do action (change scene, modify score, kill duck...)
            } else {
                play_button_sprite_rect.left = 460;
            }
            sfSprite_setTextureRect(play_button_sprite, play_button_sprite_rect);
        } else {
            play_button_sprite_rect.left = 0;
            sfSprite_setTextureRect(play_button_sprite, play_button_sprite_rect);
        }

        // Clear the window
        sfRenderWindow_clear(window, sfBlack);

        // Draw your elements
        sfRenderWindow_drawSprite(window, bg_sprite, NULL);
        sfRenderWindow_drawSprite(window, duck_sprite, NULL);
        sfRenderWindow_drawSprite(window, play_button_sprite, NULL);

        // Display everything your drawn in the window
        sfRenderWindow_display(window);
    }
    return (0);
}