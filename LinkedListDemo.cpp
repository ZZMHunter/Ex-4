// LinkedListDemo.cpp
// CSCI 235 -- Exercise 4: Linked List Operations
//
// A small driver so you can compile and run your LinkedList.cpp locally
// and see it in action before submitting. This file is PROVIDED for
// your own testing -- you do NOT submit it, and Gradescope does not
// use it; Gradescope has its own, more thorough checks.
//
// Compile and run with:
//   g++ -std=c++17 -g LinkedList.cpp LinkedListDemo.cpp -o demo
//   ./demo
//
// And on the Linux lab machines, check for leaks:
//   valgrind --leak-check=full ./demo

#include <iostream>

#include "LinkedList.hpp"

int main() {
    std::cout << "=== Task A: prepend ===\n";
    LinkedList a;
    a.prepend(30);
    a.prepend(20);
    a.prepend(10);
    std::cout << "a = " << a.toString() << "   (expect 10 -> 20 -> 30)\n";
    std::cout << "a.size() = " << a.size() << "   (expect 3)\n";

    std::cout << "\n=== Task B: append ===\n";
    LinkedList b;
    b.append(10);              // the empty-list case
    b.append(20);
    b.append(30);
    std::cout << "b = " << b.toString() << "   (expect 10 -> 20 -> 30)\n";

    std::cout << "\n=== Task C: insertAt ===\n";
    LinkedList c;
    c.append(10);
    c.append(30);
    std::cout << "insertAt(1, 20) returned "
              << (c.insertAt(1, 20) ? "true" : "false") << "   (expect true)\n";
    std::cout << "c = " << c.toString() << "   (expect 10 -> 20 -> 30)\n";
    std::cout << "insertAt(0, 5) returned "
              << (c.insertAt(0, 5) ? "true" : "false") << "   (expect true)\n";
    std::cout << "insertAt(4, 40) returned "
              << (c.insertAt(4, 40) ? "true" : "false")
              << "   (expect true -- pos == length appends)\n";
    std::cout << "insertAt(99, 7) returned "
              << (c.insertAt(99, 7) ? "true" : "false") << "   (expect false)\n";
    std::cout << "c = " << c.toString() << "   (expect 5 -> 10 -> 20 -> 30 -> 40)\n";

    std::cout << "\n=== Task D: removeValue ===\n";
    LinkedList d;
    d.append(10);
    d.append(20);
    d.append(30);
    std::cout << "removeValue(20) returned "
              << (d.removeValue(20) ? "true" : "false") << "   (expect true)\n";
    std::cout << "d = " << d.toString() << "   (expect 10 -> 30)\n";
    std::cout << "removeValue(10) returned "
              << (d.removeValue(10) ? "true" : "false")
              << "   (expect true -- removing the first node)\n";
    std::cout << "d = " << d.toString() << "   (expect 30)\n";
    std::cout << "removeValue(99) returned "
              << (d.removeValue(99) ? "true" : "false")
              << "   (expect false -- not in the list)\n";

    std::cout << "\n=== Task E: reverse ===\n";
    LinkedList e;
    e.append(7);
    e.append(14);
    e.append(21);
    e.reverse();
    std::cout << "e = " << e.toString() << "   (expect 21 -> 14 -> 7)\n";

    LinkedList f;              // reversing an empty list must not crash
    f.reverse();
    std::cout << "f = " << f.toString() << "   (expect (empty))\n";

    LinkedList g;              // reversing a one-node list
    g.append(42);
    g.reverse();
    std::cout << "g = " << g.toString() << "   (expect 42)\n";

    // === Task F (optional): removeAt ===
    // Task F is optional, so this block is commented out: leaving it active
    // would stop the program from linking until removeAt() is defined.
    // Uncomment it once you have implemented Task F.
    //
    // std::cout << "\n=== Task F (optional): removeAt ===\n";
    // LinkedList h;
    // h.append(10);
    // h.append(20);
    // h.append(30);
    // std::cout << "removeAt(1) returned "
    //           << (h.removeAt(1) ? "true" : "false") << "   (expect true)\n";
    // std::cout << "h = " << h.toString() << "   (expect 10 -> 30)\n";

    return 0;
}