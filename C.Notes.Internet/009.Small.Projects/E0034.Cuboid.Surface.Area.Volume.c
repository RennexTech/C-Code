/* Find Surface and volume of cuboid */
#include <stdio.h>

int main() {
    int l, b, h, sarea, vol;
    
    printf("Enter length, width, height of a cuboid: \n");
    scanf("%d%d%d", &l, &b, &h);
    
    // The while loop checks if any of the dimensions are invalid.
    // The `||` (OR) operator ensures that the loop runs if even one of the values is zero or negative.
    while (l <= 0 || b <= 0 || h <= 0) {
        printf("Invalid input. Dimensions must be positive. Please re-enter length, width, height:\n");
        scanf("%d%d%d", &l, &b, &h);
    }
    
    // This is the formula for the surface area of a cuboid.
    sarea = 2 * (l * b + b * h + h * l);
    
    // This is the formula for the volume of a cuboid.
    vol = l * b * h;
    
    printf("Surface area = %d, Volume = %d\n", sarea, vol);
    return 0;
}

// A generation that doesn't need to read, because they are fed 15 second summaries.

// Hunted by another 2 second summary from an AI.

// Hunted by having decision paralysis - You have too much, 4 monitors, 4090 GPU, 200 Games on that external HDD. 

// You know what you need to do to get back on track and stop feeling so heavy? 

// DECLUTTER. Delete 4 monitors, remain with 1 until the day your laziness ends, then you get yourself another one. 

// Delete that GPU, sell it. Buy a smaller one that you're not attached to. Play only 3 games, max. 

// DECLUTTER till the day you feel the laziness is out of you. Then you get yourself the best of the best. For now, survive with the ordinary. 

// You don't need stuff, you need focus. 

// Too many books and courses? Read 3 until you finish them

// Too many hobbies? Master 2 before adding more

// Too many apps? Delete everything except essentials

// ABUDANCE without discipline equals choice paralysis or decision fatigue. 

// Buy small stuff till you get disciplined, once you do, upgrade, and you will find that your emotions aren't tied to the gear, but to what you're happy to use it for, your projects, your passions.


/*

You don’t need:

The best laptop to code

The fastest GPU to learn

The biggest monitor to focus

You need consistency, focus, and grit.

A basic setup forces you to rely on skill—not specs.

When you upgrade its for efficiency, not emotional satisfaction alone. 

*/
