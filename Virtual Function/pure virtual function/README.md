<h2>Pure Virtual Function in C++</h2>

<p>A <strong>pure virtual function</strong> in C++ is a virtual function that has no implementation in the base class and must be overridden in any derived class. It is declared by assigning <code>= 0</code> at the end of the function declaration in the base class. Pure virtual functions make a class abstract, meaning you cannot instantiate objects directly from it.</p>

<h3>Syntax of a Pure Virtual Function</h3>

<pre><code>class Base {
public:
    virtual void display() = 0; // Pure virtual function
};</code></pre>

<h3>Key Points About Pure Virtual Functions</h3>
<ul>
    <li><strong>Forcing Derived Class Implementation</strong>: Any derived class must provide an implementation for the pure virtual function. If the derived class does not override the pure virtual function, it will also become an abstract class and cannot be instantiated.</li>
    <li><strong>Abstract Classes</strong>: A class with at least one pure virtual function is called an <em>abstract class</em>. Abstract classes cannot be instantiated directly; they serve as a blueprint for derived classes.</li>
    <li><strong>Usage in Polymorphism</strong>: Pure virtual functions enable polymorphism by defining a standard interface that derived classes must follow. This is useful when you want to ensure that all subclasses implement specific behaviors.</li>
</ul>

<h3>Example of a Pure Virtual Function</h3>

<pre><code>#include &lt;iostream&gt;

class Shape { // Abstract base class
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Circle\n";
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Rectangle\n";
    }
};</code></pre>

<h3>Usage in Code</h3>

<pre><code>int main() {
    Circle c;
    Rectangle r;
    
    Shape* shape1 = &c;
    Shape* shape2 = &r;

    shape1->draw(); // Output: Drawing Circle
    shape2->draw(); // Output: Drawing Rectangle

    return 0;
}</code></pre>

<h3>Summary</h3>

<p>A pure virtual function:</p>
<ul>
    <li>Is declared with <code>= 0</code> and has no implementation in the base class.</li>
    <li>Forces derived classes to implement it, making the base class an abstract class.</li>
    <li>Enables polymorphism by defining a common interface for all derived classes.</li>
</ul>
