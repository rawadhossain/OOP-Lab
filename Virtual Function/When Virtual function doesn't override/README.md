<h2>When a Derived Class Does Not Override a Virtual Function in C++</h2>

<p>A derived class may not override a virtual function in the following cases:</p>
<ol>
    <li><strong>Explicitly calling the base class version</strong>: The derived class may choose not to override the virtual function, in which case the base class's version will be used. If the derived class does implement the function but explicitly calls the base class version inside its own implementation, it is still technically overriding, but the behavior may defer to the base class.</li>
    <li><strong>Not providing an implementation</strong>: If the derived class does not provide an implementation of the virtual function, the base class's implementation will be used, effectively meaning there is no override.</li>
    <li><strong>Function signature mismatch</strong>: If the derived class provides a method with the same name but a different function signature (e.g., different return type or parameters), it will not override the base class's virtual function, and it will be treated as a new, independent function.</li>
    <li><strong>Use of <code>final</code> in the base class</strong>: If the base class marks the virtual function as <code>final</code>, it prevents further overrides in derived classes. In this case, the derived class cannot override that function.</li>
    <li><strong>The function is hidden</strong>: If the derived class defines a non-virtual function with the same name as the base class's virtual function, it "hides" the base class function. However, this is not considered an override.</li>
</ol>

<h3>Example</h3>

<p>Here’s an example illustrating when a derived class does not override a virtual function.</p>

<h4>1. Base Class with a Virtual Function</h4>

<pre><code>#include &lt;iostream&gt;

class Base {
public:
    virtual void show() {
        std::cout &lt;&lt; "Base class show function\n";
    }
};</code></pre>

<p><strong>Explanation</strong>: The <code>Base</code> class defines a virtual function <code>show()</code>.</p>

<h4>2. Derived Class without Overriding</h4>

<pre><code>class DerivedWithoutOverride : public Base {
    // No 'show()' function here, so it does not override.
};</code></pre>

<p>In this case, <code>DerivedWithoutOverride</code> does not define <code>show()</code>. So if you call <code>show()</code> on an object of <code>DerivedWithoutOverride</code>, it will use the <code>Base</code> class’s <code>show()</code> implementation.</p>

<h4>Example Usage</h4>

<pre><code>int main() {
    DerivedWithoutOverride obj1;
    obj1.show(); // Calls Base::show(), since there is no override in DerivedWithoutOverride.
    return 0;
}</code></pre>

<h4>Output:</h4>
<pre><code>Base class show function</code></pre>

<h4>3. Function Signature Mismatch</h4>

<pre><code>class DerivedSignatureMismatch : public Base {
public:
    void show(int x) { // Different parameter, not an override
        std::cout &lt;&lt; "Derived class show with parameter: " &lt;&lt; x &lt;&lt; "\n";
    }
};</code></pre>

<p>Here, <code>show(int x)</code> in <code>DerivedSignatureMismatch</code> does not override <code>Base::show()</code> because it has a different signature. It’s a separate function.</p>

<h4>Example Usage</h4>

<pre><code>int main() {
    DerivedSignatureMismatch obj2;
    obj2.show(); // Calls Base::show(), since DerivedSignatureMismatch::show(int) does not override.
    return 0;
}</code></pre>

<h4>Output:</h4>
<pre><code>Base class show function</code></pre>

<h4>4. Base Class Function Marked as <code>final</code></h4>

<pre><code>class BaseFinal {
public:
    virtual void show() final { // Prevent further overrides
        std::cout &lt;&lt; "BaseFinal class show function\n";
    }
};

class DerivedCannotOverride : public BaseFinal {
    // Attempting to override show() here would cause a compile-time error.
};</code></pre>

<p>If you try to define <code>show()</code> in <code>DerivedCannotOverride</code>, it will result in a compilation error because <code>show()</code> is marked <code>final</code> in <code>BaseFinal</code>.</p>

<h4>Summary</h4>

<p>These examples illustrate situations where a derived class does not override a base class’s virtual function:</p>
<ul>
    <li>No function provided in the derived class.</li>
    <li>A function with a different signature in the derived class.</li>
    <li>The base class function is marked as <code>final</code>.</li>
</ul>
