# Refactoring for testability in C++ ![Examples CI](https://github.com/platisd/refactoring-for-testablity-cpp/workflows/Examples%20CI/badge.svg)

Hard-to-test patterns in C++ and how to refactor them.

## What

This repository includes examples of code that is *tricky* to unit test.
The difficulty, in the context of this work, does **not** lie in its
inherent complexity when it comes to the logic or domain. For example,
software that has many branches or tries to solve a problem that needs to
follow a set of convoluted business rules, will not be examined. In fact,
all of the examples are rather simple.

The focus will be on patterns *technically* difficult to unit test
because they:
* Require irrelevant software to be tested too
  * E.g.: 3rd party libraries, classes other than the one under test
* Delay the test execution
  * E.g.: sleeps inside code under test
* Require intricate structures to be copied or written from scratch
  * E.g.: Stubs containing (a lot of) logic
* Require test details to be included in the production code
  * E.g.: `#ifdef UNIT_TESTS`
* Make changes and/or are dependent on the runtime environment
  * E.g.: Creating or reading from files

## Why

If the code is testable, writing unit tests can be particularly fun.
It can be seen as a satisfying way to *prove* your effort is correct _in
principle_. Of course, writing unit tests doe not necessarily imply
your software works as a whole, especially in conjunction with other
parts of the system. To ensure this you should look into other types of
testing, where larger pieces of functionality get verified. The most
important thing to remember is all of these tests should be *automated*.

When it comes to unit tests, you should author **testable** code that can
be verified with small and atomic tests. You should not have to test
unrelated logic nor implement complex functionality just to be able to test.
After all, unit testing should be fun and give you the confidence to develop
without worrying you "broke" something.

The three main reasons behind untestable or hard to test code, in a
not-so-random order are:

1. Project management does not care about quality
2. Developers do not know how to write testable code
3. Domain constraints on the design and technology

The latter (3), is sometimes an excuse brought forward by developers from
(2) so it needs to be taken with a grain of salt by the management if they
do not want to be part of (1).

## How

Writing testable code, does not fundamentally differ from writing *good*
code. It is however much easier to produce such code, if you write it along
or *after* your unit tests ([TDD](https://en.wikipedia.org/wiki/Test-driven_development)).
Whatever your approach may be, as a rule of thumb, writing code according to
the following guidelines and design principles, will in most cases result
in easy-to-test software:
* Write [SOLID](https://en.wikipedia.org/wiki/SOLID) code
* Prefer [Composition over inheritance](https://en.wikipedia.org/wiki/Composition_over_inheritance)
  * [C.120](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c120-use-class-hierarchies-to-represent-concepts-with-inherent-hierarchical-structure-only)
  * [C.121](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c121-if-a-base-class-is-used-as-an-interface-make-it-a-pure-abstract-class)
  * [C.129](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c129-when-designing-a-class-hierarchy-distinguish-between-implementation-inheritance-and-interface-inheritance)
  * [C.133](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c133-avoid-protected-data)
  * [I.25](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Ri-abstract)
  * [NR.7](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nr7-dont-make-all-data-members-protected)
* Avoid static and global elements
  * [I.2](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#i2-avoid-non-const-global-variables)
  * [I.3](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#i3-avoid-singletons)
  * [I.22](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Ri-global-init)
* Write code without side effects
  * [Con.1](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rconst-immutable)
  * [Con.2](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#con2-by-default-make-member-functions-const)
  * [Con.3](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#con3-by-default-pass-pointers-and-references-to-consts)
  * [Con.4](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#con4-use-const-to-define-objects-with-values-that-do-not-change-after-construction)
  * [NR.5](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#nr5-dont-use-two-phase-initialization)
  * [C.40](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c40-define-a-constructor-if-a-class-has-an-invariant)
  * [C.41](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c41-a-constructor-should-create-a-fully-initialized-object)
* Abstract away code that cannot or should not be tested
  * E.g.: 3rd party libraries, time, file operations, other classes etc

## Hard to test patterns

The patterns or, if you may, *concepts*, are organized in directories named
after their subject and are outlined below. These concepts are fundamentally
difficult to test but please keep in mind this is not necessarily the only
way to do so. Moreover, with the introduction of more feature-rich testing
frameworks, dependency injection containers etc, there may be ways to get
around the inherent lack of testability of these examples. That being said,
it is good to know how to refactor them according to object oriented design
best practices as well as the C++ Core guidelines. We illustrate this by relying
only on [GoogleTest](https://github.com/google/googletest). GoogleTest, which
includes mocking via GoogleMock is lightweight testing framework and probably
the de facto standard for C++.

The solutions proposed, do not claim to be better in performance or compliant
with any safety critical coding guidelines your project may have. They tackle
the lack of testability at a software design level and do not take into
account special domain constraints. Nonetheless, if performance is brought
forward as an argument against testable code, before taking any decisions
please refer to the [3 rules of optimization](https://wiki.c2.com/?RulesOfOptimization).

The code examples use `CMake` and need a compiler that supports C++17 or later.
In most cases they include the code `before` and `after` the refactoring efforts
in the same file under different *namespaces*. This is done for the sake of
simplicity and has the side-effect of having including indications to code smells
in the build configuration. These indications are typically followed by
comments that point them out. What is perhaps most interesting is that the
API does not change. Therefore, assuming you have well-throught APIs for your
classes then you should be able to *contain* the refactoring changes.

### Files

### Hardcoded dependencies

### Third party libraries

### `new` operators

### Time

### Law of Demeter

### Domain logic dependent on application logic
