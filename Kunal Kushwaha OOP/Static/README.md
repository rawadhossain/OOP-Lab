<h1>Understanding <code>static</code> in C++ with Examples</h1>

<p>In C++, the <code>static</code> keyword is used in various contexts to control the lifetime, scope, and binding of variables and methods. Here are some key points and examples of why and how <code>static</code> is used:</p>

<h2>1. Shared Variables Across Instances (Static Variables)</h2>
<p>A <code>static</code> variable inside a class is shared by all instances of that class. Unlike normal instance variables, which are unique to each object, a <code>static</code> variable retains its value across all objects.</p>

<h3>Example:</h3>

<pre><code>
#include &lt;iostream&gt;
using namespace std;

class Counter {
public:
    static int count;  // Static variable
    
    Counter() {
        count++;  // Increment static count for each object creation
    }
};

int Counter::count = 0;  // Initialize static variable

int main() {
    Counter c1, c2, c3;
    cout &lt;&lt; "Total objects created: " &lt;&lt; Counter::count &lt;&lt; endl;  // Output: 3
    return 0;
}
</code></pre>

<h3>Explanation:</h3>
<p>The static variable <code>count</code> is shared across all instances of <code>Counter</code>. Every time an object is created, the value of <code>count</code> increases, and the variable persists across all instances.</p>

<h2>2. Function Sharing Across All Objects (Static Methods)</h2>
<p>A <code>static</code> method can be called without creating an instance of the class. It can only access other static members of the class.</p>

<h3>Example:</h3>

<pre><code>
#include &lt;iostream&gt;
using namespace std;

class Math {
public:
    static int square(int x) {  // Static method
        return x * x;
    }
};

int main() {
    // Call static method without creating an object
    cout &lt;&lt; "Square of 5: " &lt;&lt; Math::square(5) &lt;&lt; endl;  // Output: Square of 5: 25
    return 0;
}
</code></pre>

<h3>Explanation:</h3>
<p>The method <code>square()</code> can be called directly on the class without needing to create an object. Static methods are useful when a function logically belongs to a class but doesn’t require access to instance-level data.</p>

<h2>3. Retaining Values Between Function Calls (Static Local Variables)</h2>
<p>A <code>static</code> local variable inside a function retains its value between function calls. It is initialized only once and persists for the lifetime of the program.</p>

<h3>Example:</h3>

<pre><code>
#include &lt;iostream&gt;
using namespace std;

void incrementCounter() {
    static int count = 0;  // Static local variable
    count++;
    cout &lt;&lt; "Count is: " &lt;&lt; count &lt;&lt; endl;
}

int main() {
    incrementCounter();  // Output: Count is: 1
    incrementCounter();  // Output: Count is: 2
    incrementCounter();  // Output: Count is: 3
    return 0;
}
</code></pre>

<h3>Explanation:</h3>
<p>The static local variable <code>count</code> retains its value across multiple calls to <code>incrementCounter()</code>, unlike normal local variables that are re-initialized with each function call.</p>

<h2>4. Single Instance of a Class (Singleton Pattern)</h2>
<p><code>static</code> is used in the Singleton Design Pattern to ensure that only one instance of a class can exist at a time.</p>

<h3>Example:</h3>

<pre><code>
#include &lt;iostream&gt;
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton() {}  // Private constructor

public:
    static Singleton* getInstance() {
        if (!instance) {
            instance = new Singleton();  // Create the instance if it doesn't exist
        }
        return instance;
    }

    void showMessage() {
        cout &lt;&lt; "Hello from Singleton!" &lt;&lt; endl;
    }
};

// Initialize static instance pointer to null
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s = Singleton::getInstance();
    s->showMessage();  // Output: Hello from Singleton!
    return 0;
}
</code></pre>

<h3>Explanation:</h3>
<p>The static pointer <code>instance</code> ensures that only one shared instance of the <code>Singleton</code> class exists. The <code>getInstance()</code> method controls access to this single instance.</p>

<h2>5. Constants Across Instances (Static Constants)</h2>
<p>Static constants are used when you want to define a constant value that is shared among all instances of a class.</p>

<h3>Example:</h3>

<pre><code>
#include &lt;iostream&gt;
using namespace std;

class Circle {
public:
    static const double PI;  // Static constant
    double radius;

    Circle(double r) : radius(r) {}

    double area() {
        return PI * radius * radius;
    }
};

const double Circle::PI = 3.14159;  // Initialize static constant

int main() {
    Circle c1(5);
    cout &lt;&lt; "Area of circle: " &lt;&lt; c1.area() &lt;&lt; endl;  // Output: Area of circle: 78.5398
    return 0;
}
</code></pre>

<h3>Explanation:</h3>
<p>The constant <code>PI</code> is shared across all <code>Circle</code> objects. Declaring it as <code>static</code> ensures it is defined only once and shared by all instances, improving efficiency.</p>

<h2>Key Points to Remember:</h2>
<ul>
    <li><strong>Shared Across Instances:</strong> Static variables and methods are shared by all instances of a class.</li>
    <li><strong>Independent of Objects:</strong> Static methods can be called without creating an instance.</li>
    <li><strong>Persistent Values:</strong> Static local variables retain their values between function calls.</li>
    <li><strong>Efficient Memory Usage:</strong> Static members are created once and persist throughout the program.</li>
</ul>

<h2>Summary:</h2>
<p>Static members are independent of class instances and can be used for shared functionality, constants, or to implement design patterns like Singleton.</p>
