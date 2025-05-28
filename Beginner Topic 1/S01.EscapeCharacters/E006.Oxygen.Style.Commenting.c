/**
 * 
 * @brief is like the TL;DR (Too Long; Didn't Read) of your code. 
 * 
 * It's a super short, one-liner summary of what your function, struct, or file does.
 * 
 * When someone (or a tool like Doxygen) looks at your code, this is the first thing they see. 
 * 
 * It gives them the main idea instantly, without having to read through all the details. 
 * 
 * It's like the headline of a viral post – gotta grab attention and convey the core message fast.
 * 
 */


//✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅

/**
 * 
 * @param <name> <description>
 * 
 * This is like giving a shout-out to each ingredient in your recipe. 
 * 
 * For every input (parameter) your function takes, you explain what it is and what it's for.
 *  
 */ 


/**
 * @brief Adds two numbers.
 * @param num1 The first number to add.
 * @param num2 The second number to add.
 */

int add(int num1, int num2);

//✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅

/**
 * 
 * @return <description>
 * 
 * This is where you spill the tea on what your function gives back after it's done its job. 
 * 
 * If your function returns a value, explain what that value represents.
 * 
 */

 /**
 * @brief Adds two numbers.
 * @param num1 The first number.
 * @param num2 The second number.
 * @return The sum of num1 and num2.
 */

int add(int num1, int num2);

//✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅

/**
 * 
 * @analog <analogy_text>
 * 
 * This is your secret weapon for making complex code click! 
 * 
 * We've already been using this like a boss. 
 * 
 * It's where you drop a real-world analogy to explain what the code is doing in a relatable way.
 * 
 * Why it slays: It helps beginners (and anyone, really) connect abstract code concepts to everyday experiences. 
 * 
 * It's how you make the learning vibe.

 */

 //✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅

/**
 * @note <note_text>
 * 
 * Vibe Check: This is for dropping extra wisdom or important details that don't fit into the main description 
 * 
 * or parameters. Like a little asterisk (*) with extra info at the bottom of a page.
 * 
 */

 /**
 * @brief Calculates the square root.
 * @param num The number to find the square root of.
 * @return The square root of num.
 * @note This function returns NaN (Not a Number) if num is negative.
 */

double calculate_sqrt(double num);

//✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅

/**
 * 
 * @see <related_function_or_topic>
 * 
 * This is like putting a "See Also" link in your comments. 
 * 
 * It points to other functions, files, or concepts that are related, 
 * 
 * so someone can easily find more info if they need it.
 * 
 */

/**
 * @brief Clears the input buffer.
 * @see get_integer_input
 * @see fgets
 */

 void clear_input_buffer();

 
//✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅


/**
 * 
 * @warning <warning_text>
 * 
 * This is your "Danger! Proceed with Caution!" sign. 
 * 
 * Use it to highlight potential pitfalls, tricky behaviors, or things that might break if used incorrectly.

 */

 /**
 * @brief Directly accesses hardware register.
 * @warning Incorrect usage can lead to system instability or crashes.
 */

void write_to_register(int value);

//✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅

/**
 * 
 * @todo <task_description>
 * 
 * This is your "To-Do List" for future you or your squad. 
 * 
 * Use it for quick notes about things that still need to be done, improved, or fixed in that code section.

 */

 /**
 * @brief Placeholder for future authentication logic.
 * @todo Implement actual user authentication using OAuth.
 */

void authenticate_user();

//✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅✅

/**
 * 
 * Why Bother with All This? (The Pro-Beginner Mindset).
 * 
 * Readability is King: Your code isn't just for the compiler; it's for humans. 
 * 
 * Good comments make your code a joy to read, not a headache.
 * 
 * Collaboration: When you work with others (or even your future self), clear comments mean less head-scratching and more smooth sailing.
 * 
 * Documentation Tools: Tools like Doxygen can actually read these comments and automatically generate fancy documentation (like web pages or PDFs) for your project. That's next-level pro!
 * 
 * Debugging: When things go sideways, well-commented code helps you (or anyone else) quickly understand what each part is supposed to do, making debugging less of a nightmare.
 * 
 * You're already on the right track by asking about this, fam. Keep that energy, and your code will not only work but also tell a clear, compelling story!
 * 
 */