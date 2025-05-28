/**
 *
 * _Bool is like giving your program a way to say “yes” or “no”.
 *
 * Think of it as a light switch — it’s either ON (true) or OFF (false).
 *
 * It's the real C way to represent boolean values, introduced in C99.
 *
 * You might’ve seen ‘true’ and ‘false’ in other languages — same vibe,
 * just more official here with stdbool.h.
 *
 * Use it when your code needs to make decisions, track flags, or loop based on conditions.
 *
 */

#include <stdio.h>
#include <stdbool.h> // Makes 'true' and 'false' keywords usable

int main() {
    printf("--------------------------------------------\n");
    printf("33. _Bool\n");
    printf("--------------------------------------------\n");
    printf("'_Bool' gives C an official way to say TRUE or FALSE. It’s perfect for tracking flags, states, or decisions.\n");
    printf("--------------------------------------------\n");

    _Bool doorIsLocked = true;
    _Bool hasKey = false;

    if (doorIsLocked) {
        printf("The door is locked.\n");

        if (hasKey) {
            printf("You have the key! Unlocking door...\n");
            doorIsLocked = false;
        } else {
            printf("No key. You can’t get in. 🔒🚫\n");
        }
    }

    if (!doorIsLocked) {
        printf("Door is now unlocked. You may enter! 🚪✅\n");
    }

    return 0;
}


//=================================== ANOTHER EXAMPLE ============================

#include <stdio.h>   // For the mic (printf)
#include <stdbool.h> // For 'bool', 'true', 'false' (makes _Bool way easier to use)
#include <unistd.h>  // For chilling between prints (sleep)

/**
 * * _Bool is like a simple 'Yes/No' or 'True/False' switch. 
 * * It's the actual C boolean type, way clearer than using 0 or 1 for logic. 
 * * You usually see it as 'bool' by including <stdbool.h>, which is like giving it a cool nickname.
 * * It's all about making your code's logic super obvious.
 * */

int main() {
    printf("--------------------------------------------\n");
    printf("33. _Bool (C99)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The OG boolean type! It's like a simple 'Yes/No' or 'True/False' switch. Way clearer than using 0 or 1 for logic. You usually see it as 'bool' by including <stdbool.h>.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    // Using _Bool directly (less common, but works)
    _Bool is_light_on = 1; // 1 means true, 0 means false
    printf("Is the light switch ON? (using _Bool): %s\n", is_light_on ? "Yes" : "No");
    sleep(1);

    // Using 'bool' from <stdbool.h> (the cool, readable way)
    bool is_door_open = true; // 'true' is clearer than '1'
    bool is_alarm_active = false; // 'false' is clearer than '0'

    printf("Is the door open? (using bool): %s\n", is_door_open ? "Yep, it's open! 🚪" : "Nah, it's closed.");
    sleep(1);
    printf("Is the alarm active? (using bool): %s\n", is_alarm_active ? "🚨 ALERT! 🚨" : "All clear. ✅");
    sleep(1);

    // You can use bool in conditions directly
    if (is_door_open) {
        printf("Someone left the door open! 😬\n");
    } else {
        printf("Door is secure. 👍\n");
    }

    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}


