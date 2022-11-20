# Introduction to CSFML

##### This workshop aims to teach you the basics of CSFML. You have a working window, but now we'll add some stuff into it. Textures, sprites, make sure to understand the important terms by taking a look at the [official website]().

##### It's written in SFML but it doesn't matter that much to understand the concepts, however if you wanna check out the types, structures, functions and their functionalities, you might wanna refer to [this unofficial CSFML documentation](https://26.customprotocol.com/csfml/). It will be really useful, trust me !

###### After the workshop, the corrected exercises will be in separated files, each one of them with the added functionality of the 

### Step 0 - Setup

In order to get started with the CSFML, you'll have to install the CSFML library.

#### Linux

You should already have it installed from the C Pool, or by using the ``` build_csfml.sh ``` executable file available in the repository.

#### MacOS

If you're using a Mac M1 chip, the 2.5.1 library is already built in the ``` __OSX__ ``` folder. If you wish to build it for another version or processor (X86 / ARM), please refer to the official documentation.

The most common folder to find your built library is in ``` /opt/homebrew/Cellar/csfml/ ```. Your can take the ``` include ``` and ``` lib ``` file and replace the existing ones in the ``` ___OSX__ ``` folder in the repository.

If there are any deprecated functions, you can removed them from the compiled library to avoid unnecessary warnings.

**You should now be able to open a window in CSFML.**

### Step 1 - Animating stuff

In this first step, you'll have to create and draw an animated duck. There's a sprite-sheet available in the assets folder, but feel free to add your own if you feel like it.

### Step 2 - Movement!

It's better to have an actual moving flying duck rather than being stuck in a single position. Could you make him move a bit ? How about going east? Could you make it re appear on the left of the screen after it crossed the right side? Could be neat!

### Step 3 - Creating a button

I'd like you to make a 3-state button in order to get in the game. When it's idle, when you hover and it a third one when you click on it. There's a beautiful hand-made sprite-sheet, you can even add other ones like the settings or quit button to make it look like a real game!

### Bonus - Pixel-perfect button

Well well well who do we have here. It seems hard at first but I can tell you it isn't. I'd like to be able to click on my button but only when we're on the button itself. Yeah it's pretty fun to make a button, but why are you able to click on the transparent part of a button? Don't just take a rectangle area into account, you might wanna check the RGBA values.

.....

you're done?

...

Good job. Feel free to enhance your game by adding music, sounds, enemies, scenes ?