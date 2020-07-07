/*
 * Recursive and stack-based solutions to the Towers of Hanoi problem.
 *
 * Author: Drue Coles
 */
#include <iostream>
#include <stack>
using namespace std;

void rec_towers1(int, char, char, char); // recursive implementation
void rec_towers2(int, char, char, char); // tail recursion replaced with loop
void rec_towers3(int, char, char, char); // a simplification using GOTOs
void stack_towers(int, char, char, char); // stack-based implementation
void stack_towers2(int, char, char, char); // GOTOless stack-based implementation

// a convenience for simplifying output statements
void print(char start, char finish) {
    cout << "Move disk from " << start << " to " << finish << endl;
}

// stores local data to be saved on a stack in simulated recursion
struct Frame {

	Frame(int n, char a, char b, char c) {
		num_disks = n;
		start = a;
		finish = b;
		spare = c;
	}

    int num_disks;
    char start;
    char finish;
    char spare;
};

// tests each implementation
int main() {
    const int num_disks = 3;
    rec_towers1(num_disks, 'A', 'B', 'C');
    cout << endl;

    rec_towers2(num_disks, 'A', 'B', 'C');
    cout << endl;

    rec_towers3(num_disks, 'A', 'B', 'C');
    cout << endl;

    stack_towers(num_disks, 'A', 'B', 'C');
    cout << endl;

    stack_towers2(num_disks, 'A', 'B', 'C');
    cout << endl;
    return 0;
}

void rec_towers1(int n, char start, char finish, char spare) {
    if (n == 1) {
        print(start, finish);
    }
    else {
        rec_towers1(n-1, start, spare, finish);
        print(start, finish);
        rec_towers1(n-1, spare, finish, start);
    }
}

// tail recursion replaced with a loop
void rec_towers2(int n, char start, char finish, char spare) {
    while (n > 1) {
        rec_towers2(n-1, start, spare, finish);
        print(start, finish);

        // replace rec_towers2(n-1, spare, finish, start);
        n--;
        int temp = spare;
        spare = start;
        start = temp;
    }
    print(start, finish);
}

// replace loop with GOTOs
void rec_towers3(int n, char start, char finish, char spare) {
    START:

    if (n == 1) {
        print(start, finish);
        return;
    }

    rec_towers3(n-1, start, spare, finish);
    print(start, finish);

    n--;
    int temp = spare;
    spare = start;
    start = temp;

    goto START;
}

//  stack-based implementation
void stack_towers(int n, char start, char finish, char spare) {
    int temp;
    stack<Frame> stack;

    START:

    if (n == 1) {
        print(start, finish);
        goto CONTINUE;
    }

    // Replacing: rec_towers3(n-1, start, spare, finish);
    // Push current environment onto stack and change the
    // variables to parameters of the new environment.
    stack.push( Frame(n, start, finish, spare) );
    n--;
    temp = spare;
    spare = finish;
    finish = temp;
    goto START;

    CONTINUE: // Return from recursive call.

    if (stack.empty()) {
        return;
    } else { // Restore the environment.
        Frame frame = stack.top();
        stack.pop();
        n = frame.num_disks;
        start = frame.start;
        spare = frame.spare;
        finish = frame.finish;

        print(start, finish);
        n--;
        temp = spare;
        spare = start;
        start = temp;
        goto START;
    }
}

// stack-based without GOTOs
void stack_towers2(int n, char start, char finish, char spare) {
    stack<Frame> stack;

    while (true) {
        if (n == 1) {
            print(start, finish);

            if (stack.empty()) {
                return;
            }

            Frame f = stack.top(); // return to previous environment
            stack.pop();
            n = f.num_disks;
            start = f.start;
            spare = f.spare;
            finish = f.finish;
            print(start, finish);

            n--;
            int temp = spare;
            spare = start;
            start = temp;
        } else { // save current environment
            stack.push(Frame(n, start, finish, spare));
            n--;
            int temp = spare;
            spare = finish;
            finish = temp;
        }
    }
}