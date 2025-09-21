#include <windows.h>

// These are like our main characters—handles to the list box and the text box.
// A handle is just an ID card, a way for our code to point to these windows
// and say, "Hey, I need to talk to you."
HWND hwndList, hwndEdit;
HINSTANCE hInst;

// This function is the "Add" button's brain.
// When you click 'Add', this gets called to grab your text and put it in the list.
void AddTask() {
    // We get the text you typed. It's like reading the note you just wrote down.
    char buffer[256];
    GetWindowText(hwndEdit, buffer, sizeof(buffer));

    // A quick sanity check. We don't want to add a blank task.
    if (strlen(buffer) > 0) {
        // Analogy: We're sending a direct command to the list box.
        // It's like texting a friend: "Hey, add this to our list."
        // LB_ADDSTRING is the command, and `buffer` is the message.
        SendMessage(hwndList, LB_ADDSTRING, 0, (LPARAM)buffer);
        // Once we're done, we clear the text box so it's ready for the next task.
        SetWindowText(hwndEdit, "");
    }
}

// This function is the "Remove" button's brain.
// When you click 'Remove', this gets called to take a task off the list.
void RemoveTask() {
    // First, we ask the list box what task is currently selected.
    // It's like asking your friend, "Which item on the list are you pointing at?"
    int selectedIndex = SendMessage(hwndList, LB_GETCURSEL, 0, 0);

    // If something is actually selected (not an error), we remove it.
    if (selectedIndex != LB_ERR) {
        // Analogy: We're sending another direct text message to the list box,
        // this time with a new command: "Delete the item at this position."
        SendMessage(hwndList, LB_DELETESTRING, (WPARAM)selectedIndex, 0);
    }
}

// This is the receptionist for our window.
// Every window has one of these. It sits there, waiting for messages from
// the operating system. It's like a dispatcher at a call center—it takes
// calls about what's happening (mouse clicks, key presses, etc.) and
// decides what to do with them.
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    // The switch statement is the dispatcher's rule book. It checks the type
    // of message (`msg`) and runs the right code for it.
    switch (msg) {
        // This is the message we get when the window is first created.
        // This is where we create all our UI elements: the list, the text box,
        // and the two buttons. It's like setting up all the furniture in a new room.
        case WM_CREATE:
            hwndList = CreateWindow("LISTBOX", NULL, WS_VISIBLE | WS_CHILD | LBS_STANDARD,
                                    10, 10, 200, 200, hwnd, NULL, hInst, NULL);
            hwndEdit = CreateWindow("EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER,
                                    220, 10, 150, 30, hwnd, NULL, hInst, NULL);
            // We give the buttons an ID number (1 and 2) so we can tell them apart.
            CreateWindow("BUTTON", "Add", WS_VISIBLE | WS_CHILD,
                          220, 50, 75, 30, hwnd, (HMENU)1, hInst, NULL);
            CreateWindow("BUTTON", "Remove", WS_VISIBLE | WS_CHILD,
                          295, 50, 75, 30, hwnd, (HMENU)2, hInst, NULL);
            break;
        // This message comes from a control, like when a button is clicked.
        case WM_COMMAND:
            // This nested switch checks the button's ID number to know
            // which one was clicked.
            switch (LOWORD(wParam)) {
                case 1: // Add button clicked
                    AddTask();
                    break;
                case 2: // Remove button clicked
                    RemoveTask();
                    break;
            }
            break;
        // This is the message we get when someone tries to close the window.
        // We tell the OS to destroy the window.
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        // This is the message we get when the window is actually destroyed.
        // We send a final message to the OS to quit the application.
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        // If we don't handle a message, we let the default window procedure handle it.
        // Think of it as a safety net for any messages we don't recognize.
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// This is the main entry point for the entire application.
// Analogy: This is the grand opening of our store. It sets up the store's
// sign, builds the main building (the window), and then opens the doors
// to the public. Once the doors are open, it just sits back and handles
// customer traffic (the message loop).
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    hInst = hInstance;
    HWND hwnd;
    MSG Msg;
    WNDCLASSEX wc;

    // This is the blueprint for our window.
    // It tells the OS how our window should look and behave.
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "ToDoList";
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Using the blueprint, we build the actual window.
    hwnd = CreateWindow("ToDoList", "To-Do List", WS_OVERLAPPEDWINDOW,
                        CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // This is the heart of the app. It's an endless loop that continuously checks
    // for messages from the OS, like button clicks or mouse movements.
    // It's what keeps the app responsive.
    while (GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}
