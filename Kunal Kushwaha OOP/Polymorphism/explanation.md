<div class="markdown prose w-full break-words dark:prose-invert dark"><p>The way you're expressing your C++ code with a <strong>base class pointer</strong> (<code>Shapes*</code>) pointing to objects of <strong>derived classes</strong> like <code>Circle</code> and <code>Square</code> serves a fundamental purpose in object-oriented programming: <strong>polymorphism</strong>.</p><p>Here's the <strong>motto</strong> or purpose behind this approach:</p><h3>1. <strong>Polymorphism</strong>:</h3><ul><li><strong>Polymorphism</strong> allows one object (like <code>Shapes*</code>) to take on many forms (e.g., <code>Circle</code>, <code>Square</code>, <code>Triangle</code>). It lets you <strong>write flexible code</strong> that can work with objects of different types (derived classes) through a <strong>common interface</strong> (the base class).</li><li>In your example, you're using a <code>Shapes*</code> pointer to refer to different types of shapes (<code>Circle</code>, <code>Square</code>, etc.). This enables your code to handle <strong>different behaviors</strong> (i.e., calculating the area of different shapes) while interacting with them through the same interface (<code>Shapes</code>).</li></ul><h3>2. <strong>Decoupling</strong> (Reducing Dependency on Specific Classes):</h3><ul><li>By using a pointer to the base class (<code>Shapes*</code>), your code becomes less dependent on specific types like <code>Circle</code> or <code>Square</code>. Instead, it interacts with the base class (<code>Shapes</code>), making it easier to extend the program by adding new shape types (like <code>Triangle</code> or <code>Rectangle</code>) without changing the existing logic in <code>main()</code>.</li><li>This makes the code more <strong>extensible</strong> and <strong>maintainable</strong>.</li></ul><h3>3. <strong>Dynamic Method Dispatch</strong> (With Virtual Functions):</h3><ul><li>When you mark the base class method (<code>area()</code>) as <code>virtual</code> and override it in derived classes, it enables <strong>dynamic method dispatch</strong>. This means that the <strong>actual method</strong> that gets called is determined at <strong>runtime</strong>, based on the <strong>actual type of the object</strong> (not the type of the pointer).</li><li>If your <code>area()</code> function were marked as <code>virtual</code> in the <code>Shapes</code> class, the call <code>circle-&gt;area();</code> would automatically call the <code>Circle</code>'s <code>area()</code> method even though you're using a <code>Shapes*</code> pointer. Without <code>virtual</code>, the base class's method will always be called.</li></ul><h3>4. <strong>Reusability and Flexibility</strong>:</h3><ul><li>You can reuse this pattern whenever you need to work with a collection of different shapes but don't want to write separate handling logic for each shape. By using polymorphism, your code can <strong>handle various shapes generically</strong>.</li></ul><h3>How It Works:</h3><ul><li>In your example:<pre class="!overflow-visible"><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary">cpp</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"><button class="flex gap-1 items-center py-1"><svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg" class="icon-sm"><path fill-rule="evenodd" clip-rule="evenodd" d="M7 5C7 3.34315 8.34315 2 10 2H19C20.6569 2 22 3.34315 22 5V14C22 15.6569 20.6569 17 19 17H17V19C17 20.6569 15.6569 22 14 22H5C3.34315 22 2 20.6569 2 19V10C2 8.34315 3.34315 7 5 7H7V5ZM9 7H14C15.6569 7 17 8.34315 17 10V15H19C19.5523 15 20 14.5523 20 14V5C20 4.44772 19.5523 4 19 4H10C9.44772 4 9 4.44772 9 5V7ZM5 9C4.44772 9 4 9.44772 4 10V19C4 19.5523 4.44772 20 5 20H14C14.5523 20 15 19.5523 15 19V10C15 9.44772 14.5523 9 14 9H5Z" fill="currentColor"></path></svg>Copy code</button></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">Shapes* circle = <span class="hljs-keyword">new</span> <span class="hljs-built_in">Circle</span>();
</code></div></div></pre>You create a pointer of type <code>Shapes*</code>, but it points to an object of the <code>Circle</code> class. Later, when you call <code>circle-&gt;area()</code>, it could (with <code>virtual</code>) call the <code>Circle</code>'s method at runtime, based on the actual object type (<code>Circle</code>), even though the pointer is of the base class type (<code>Shapes*</code>).</li></ul><h3>Why Use This Approach?</h3><ul><li><p>Imagine a scenario where you need to handle different types of shapes. Without polymorphism, you might end up writing code like this:</p><pre class="!overflow-visible"><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary">cpp</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"><button class="flex gap-1 items-center py-1"><svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg" class="icon-sm"><path fill-rule="evenodd" clip-rule="evenodd" d="M7 5C7 3.34315 8.34315 2 10 2H19C20.6569 2 22 3.34315 22 5V14C22 15.6569 20.6569 17 19 17H17V19C17 20.6569 15.6569 22 14 22H5C3.34315 22 2 20.6569 2 19V10C2 8.34315 3.34315 7 5 7H7V5ZM9 7H14C15.6569 7 17 8.34315 17 10V15H19C19.5523 15 20 14.5523 20 14V5C20 4.44772 19.5523 4 19 4H10C9.44772 4 9 4.44772 9 5V7ZM5 9C4.44772 9 4 9.44772 4 10V19C4 19.5523 4.44772 20 5 20H14C14.5523 20 15 19.5523 15 19V10C15 9.44772 14.5523 9 14 9H5Z" fill="currentColor"></path></svg>Copy code</button></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">Circle circle;
Square square;
circle.<span class="hljs-built_in">area</span>();
square.<span class="hljs-built_in">area</span>();
</code></div></div></pre><p>But if you wanted to add new shapes like <code>Triangle</code> or <code>Rectangle</code>, you'd have to modify your <code>main()</code> function every time.</p></li><li><p>By using a <strong>common base class</strong> (<code>Shapes* shape</code>), you can treat all the shapes in a <strong>uniform way</strong>. This means you don't need to change the code when adding new shape types:</p><pre class="!overflow-visible"><div class="contain-inline-size rounded-md border-[0.5px] border-token-border-medium relative bg-token-sidebar-surface-primary dark:bg-gray-950"><div class="flex items-center text-token-text-secondary px-4 py-2 text-xs font-sans justify-between rounded-t-md h-9 bg-token-sidebar-surface-primary dark:bg-token-main-surface-secondary">cpp</div><div class="sticky top-9 md:top-[5.75rem]"><div class="absolute bottom-0 right-2 flex h-9 items-center"><div class="flex items-center rounded bg-token-sidebar-surface-primary px-2 font-sans text-xs text-token-text-secondary dark:bg-token-main-surface-secondary"><span class="" data-state="closed"><button class="flex gap-1 items-center py-1"><svg width="24" height="24" viewBox="0 0 24 24" fill="none" xmlns="http://www.w3.org/2000/svg" class="icon-sm"><path fill-rule="evenodd" clip-rule="evenodd" d="M7 5C7 3.34315 8.34315 2 10 2H19C20.6569 2 22 3.34315 22 5V14C22 15.6569 20.6569 17 19 17H17V19C17 20.6569 15.6569 22 14 22H5C3.34315 22 2 20.6569 2 19V10C2 8.34315 3.34315 7 5 7H7V5ZM9 7H14C15.6569 7 17 8.34315 17 10V15H19C19.5523 15 20 14.5523 20 14V5C20 4.44772 19.5523 4 19 4H10C9.44772 4 9 4.44772 9 5V7ZM5 9C4.44772 9 4 9.44772 4 10V19C4 19.5523 4.44772 20 5 20H14C14.5523 20 15 19.5523 15 19V10C15 9.44772 14.5523 9 14 9H5Z" fill="currentColor"></path></svg>Copy code</button></span></div></div></div><div class="overflow-y-auto p-4" dir="ltr"><code class="!whitespace-pre hljs language-cpp">Shapes* shape = <span class="hljs-keyword">new</span> <span class="hljs-built_in">Circle</span>();
shape-&gt;<span class="hljs-built_in">area</span>(); <span class="hljs-comment">// Calls Circle's area()</span>

shape = <span class="hljs-keyword">new</span> <span class="hljs-built_in">Square</span>();
shape-&gt;<span class="hljs-built_in">area</span>(); <span class="hljs-comment">// Calls Square's area()</span>
</code></div></div></pre><p>As long as the base class defines the <code>area()</code> method and the derived classes override it, your code will work for any shape!</p></li></ul><h3>Key Takeaways:</h3><ul><li><strong>Polymorphism</strong> lets you write flexible, extensible code where base class pointers can point to objects of derived classes, enabling dynamic behavior.</li><li>If your <code>area()</code> function were <strong>virtual</strong>, the correct <code>area()</code> implementation (based on the actual object type) would be called at runtime, allowing you to switch between different types of shapes seamlessly.</li></ul><p>This approach is a powerful OOP principle that reduces code duplication, enhances maintainability, and improves flexibility in handling different types of objects through a common interface.</p><p>Let me know if you'd like more clarification or further examples!</p></div>