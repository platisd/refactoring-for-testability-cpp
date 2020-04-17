# Refactoring for testability in C++ ![Examples CI](https://github.com/platisd/refactoring-for-testablity-cpp/workflows/Examples%20CI/badge.svg)

Hard-to-test patterns in C++ and how to refactor them.

### Contents

* [What](#what)
* [Why](#why)
* [How](#how)
* [Hard-to-test patterns](#hard-to-test-patterns)
  * [Files](#files)
  * [Hardcoded dependencies](#hardcoded-dependencies)
  * [Third-party libraries](#third-party-libraries)
  * [`new` operators](#new-operators)
  * [Time](#time)
  * [Law of Demeter](#law-of-demeter)
  * [Domain logic dependent on application logic](#domain-logic-dependent-on-application-logic)
* [License](#license)

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

## Hard-to-test patterns

The patterns or, if you may, *concepts*, are organized in directories named
after their subject and are outlined below. These concepts are fundamentally
difficult to test but please keep in mind this is not necessarily the only
way to do so. Moreover, with the introduction of more feature-rich testing
frameworks, dependency injection containers etc, there may be ways to get
around the inherent lack of testability of these examples. That being said,
it is good to know how to refactor them according to object oriented design
best practices as well as the C++ Core guidelines. We illustrate this by relying
only on [GoogleTest](https://github.com/google/googletest). GoogleTest, which
includes mocking via GoogleMock is a lightweight testing framework and probably
the de facto standard for C++.

The solutions proposed, do not claim to be better in performance nor compliant
with any safety0critical coding guidelines your project may have. They tackle
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
API does not change. Therefore, assuming you have well-thought APIs for your
classes then you should be able to *contain* the refactoring changes.

All the examples are runnable and inspired by real-life situations.

### Files

Reading from and writing to files is a relatively common and simple task. However,
when it is time for unit tests, things get trickier. This is because if we actually
start writing or reading files during our unit tests, we are on one hand verifying
that our filesystem operations work on the other we are dependent on our host
environment and its file structure.

#### Example(s)

```cpp
bool write(const std::string& filePath, const std ::string& content)
{
    std::ofstream outfile(filePath.c_str(), std::ios::trunc);
    if (outfile.good())
    {
        outfile << content << std::endl;
    }

    return outfile.good();
}

std::optional<std::string> read(const std::string& filePath)
{
    std::ifstream fileToRead(filePath);
    std::stringstream buffer;
    buffer << fileToRead.rdbuf();

    if (buffer.good())
    {
        return std::make_optional(buffer.str());
    }

    return std::nullopt;
}

```

#### Alternative(s)

Reading and writing to files should *not* be unit tested. Instead, you should
**abstract** these operations out into, preferably separate, interfaces and
use them instead.

```cpp
struct FileReader
{
    virtual ~FileReader() = default;

    virtual std::optional<std::string>
    read(const std::string& filePath) const = 0;
};

struct FileWriter
{
    virtual ~FileWriter() = default;

    virtual bool write(const std::string& filePath,
                       const std ::string& content) const = 0;
};
```

| Refactored file(s)                                   | Unit tests                                           |
| ---------------------------------------------------- | ---------------------------------------------------- |
| [FileEncoder.hpp](010-files/include/FileEncoder.hpp) | [FileEncoder_test.cpp](test/ut/FileEncoder_test.cpp) |
| [FileEncoder.cpp](010-files/src/FileEncoder.cpp)     |                                                      |

### Hardcoded dependencies

Hardcoding dependencies results in having to include *unrelated*, to our unit under
test, code in our test setup. Consequently, we end up testing more than we should
and particularly code that has likely been tested before. This also means our test
cases are no longer *atomic*. Testing aside, our implementation is tightly coupled
to another implementation which reduces its reusability. Additionally, changes in
the implementation of the hardcoded dependencies may trigger changes in our unit
under test, which reduces maintainability and hinders software evolution.

There are two ways we may end up in this situation:
1. Using *concrete* classes
2. Extending *concrete* classes

#### Example(s)

```cpp
// Using a concrete class
struct DirectionlessOdometer
{
    DirectionlessOdometer(int pulsePin, int pulsesPerMeter);

    double getDistance() const;

protected:
    MyInterruptServiceManager mInterruptManager;
};

// Extending (and using) a concrete class
struct DirectionalOdometer : public DirectionlessOdometer
{
    DirectionalOdometer(int directionPin, int pulsePin, int pulsesPerMeter);

private:
    MyPinReader mPinReader;
};
```

#### Alternative(s)

We separate the *common* functionality in a new class and stop extending
the concrete class. This has the added semantic benefit of avoiding to impose
a parent-child relationship. After all, a `DirectionalOdometer` is *not* really
a `DirectionlessOdometer`, is it? Then, we *inject* the *abstracted* resources
that are being used into the classes that use them via the respective constructors.

```cpp
struct DirectionlessOdometer
{
    DirectionlessOdometer(Encoder& encoder,
                          InterruptServiceManager& interruptServiceManager,
                          int pulsePin);

    double getDistance() const;

private:
    Encoder& mEncoder;
};

struct DirectionalOdometer
{
    DirectionalOdometer(Encoder& encoder,
                        InterruptServiceManager& interruptServiceManager,
                        PinReader& pinReader,
                        int directionPin,
                        int pulsePin);

    double getDistance() const;

private:
    Encoder& mEncoder;
    PinReader& mPinReader;
};
```

| Refactored file(s)                                                                        | Unit tests                                       |
| ----------------------------------------------------------------------------------------- | ------------------------------------------------ |
| [DirectionlessOdometer.hpp](020-hardcoded_dependencies/include/DirectionlessOdometer.hpp) | [Odometers_test.cpp](test/ut/Odometers_test.cpp) |
| [DirectionlessOdometer.cpp](020-hardcoded_dependencies/src/DirectionlessOdometer.cpp)     |                                                  |
| [DirectionalOdometer.hpp](020-hardcoded_dependencies/include/DirectionalOdometer.hpp)     |                                                  |
| [DirectionlessOdometer.cpp](020-hardcoded_dependencies/src/DirectionalOdometer.cpp)       |                                                  |

### Third-party libraries

Using third-party libraries instead of reinventing the wheel is a must if you do
not want to spend your time in commodity functionality that does not differentiate
your product in any valuable way. Like hardcoded dependencies, we should not be pulling
them in our unit tests as they are unrelated and they should not be tested, at
least by our unit tests.

#### Example(s)

```cpp
std::optional<std::chrono::milliseconds>
PlatisSolutionsBenchmarker::getResponseTime() const
{
    const auto start        = std::chrono::system_clock::now();
    auto downloadSuccessful = false;
    if (auto curl = curl_easy_init())
    {
        auto fp = fopen(kFilePath, "wb");
        curl_easy_setopt(curl, CURLOPT_URL, kUrl);
        curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        downloadSuccessful = curl_easy_perform(curl) == CURLE_OK;

        fclose(fp);
        curl_easy_cleanup(curl);
    }
    const auto end = std::chrono::system_clock::now();

    if (downloadSuccessful)
    {
        const auto elapsedTime
            = std::chrono::duration_cast<std::chrono::milliseconds>(end
                                                                    - start);
        return std::make_optional(elapsedTime);
    }

    return std::nullopt;
}
```

#### Alternative(s)

Instead of using [libcurl](https://curl.haxx.se/libcurl/)) directly in our code, we
create a wrapper class around it. This wrapper class, **abstracts the business value**
we are after when using this 3rd party software. As a result, we do not have to be
*actually* using `curl` to download things during our unit tests. Furtheremore, we are
also not limited to `curl`. If we opt for another way of downloading files, we can
simply inject a different `Downloader` implementation.

```cpp
struct Downloader
{
    virtual ~Downloader() = default;

    virtual bool download(const std::string& url,
                          const std::string& destination) const = 0;
};

std::optional<std::chrono::milliseconds>
PlatisSolutionsBenchmarker::getResponseTime() const
{
    const auto start              = std::chrono::system_clock::now();
    const auto downloadSuccessful = mDownloader.download(kUrl, kFilePath);
    const auto end                = std::chrono::system_clock::now();

    if (downloadSuccessful)
    {
        const auto elapsedTime
            = std::chrono::duration_cast<std::chrono::milliseconds>(end
                                                                    - start);
        return std::make_optional(elapsedTime);
    }

    return std::nullopt;
}
```

| Refactored file(s)                                                                       | Unit tests                                                                         |
| ---------------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------- |
| [PlatisSolutionsBenchmarker.hpp](030-third_party/include/PlatisSolutionsBenchmarker.hpp) | [PlatisSolutionsBenchmarker_test.cpp](test/ut/PlatisSolutionsBenchmarker_test.cpp) |
| [PlatisSolutionsBenchmarker.cpp](030-third_party/src/PlatisSolutionsBenchmarker.cpp)     |                                                                                    |


### `new` operators

Occasionally, it is not possible to inject dependencies because they may not be
known during compile-time. For example, if you have a machine that can be connected
to many different parts, we would need to figure out **during run-time** what those
parts are to represent them programmatically. This is achieved by instantiating the
new resource. Hopefully, you are not using the `new` operator but instead create
your resources on the stack or using smart pointers. Whatever the case may be, testing
this behavior is difficult since your test cases have no knowledge of the newly
created resources.

#### Example(s)

```cpp
struct Sensor
{
    virtual ~Sensor() = default;

    virtual int getDistance() const = 0;
};

enum class SensorIdentifier
{
    LaserSensor      = 0x2A,
    InfraredSensor   = 0x1C,
    UltrasonicSensor = 0x1D
};

struct SensorScanner
{
    virtual ~SensorScanner() = default;

    virtual std::vector<SensorIdentifier> scan() const = 0;
};

struct SensorManager
{
    SensorManager(SensorScanner& sensorScanner);

    std::vector<int> getSurroundingDistances() const;

private:
    std::vector<std::unique_ptr<Sensor>> mSensors;
};

SensorManager::SensorManager(SensorScanner& sensorScanner)
{
    const auto detectedSensorIds = sensorScanner.scan();

    for (const auto& id : detectedSensorIds)
    {
        switch (id)
        {
        case SensorIdentifier::InfraredSensor:
            mSensors.emplace_back(std::make_unique<InfraredSensor>());
            break;
        case SensorIdentifier::UltrasonicSensor:
            mSensors.emplace_back(std::make_unique<UltrasonicSensor>());
            break;
        case SensorIdentifier::LaserSensor:
            mSensors.emplace_back(std::make_unique<LaserSensor>());
            break;
        default:
            throw std::logic_error("Unknown sensor");
        }
    }
}
```

#### Alternative(s)

We may be able to determine what the `sensorScanner` returns, as it is a resource we
know will be needed during compilation. However, we have no control of the `private`
variable `mSensors` and do not even think of making it `public` or `protected` just
increase your coverage. To make things worse, we need to pull in concrete classes
(e.g. `InfraredSensor` etc) which aside from being unrelated to our unit under test,
may also be tricky (e.g. the sensors cannot be compiled for our host machine).
Instead, you should use an abstract factory that will be injected and therefore
controllable by our tests.

By the way, you should *not* use the `SensorIdentifier` as an input to the factory
as you will couple two domains that are not dependent on each other. And even if
they are coupled at the moment, that does not mean they will be in the future or
another variant of your product.

```cpp
enum class SensorType
{
    Infrared,
    Ultrasonic,
    Laser,
    Lidar,
    Odometer,
    Radar
};

struct SensorFactory
{
    virtual ~SensorFactory() = default;

    virtual std::unique_ptr<Sensor> getSensor(SensorType sensorType) const = 0;
};

struct SensorManager
{
    SensorManager(SensorScanner& sensorScanner, SensorFactory& sensorFactory);

    std::vector<int> getSurroundingDistances() const;

private:
    std::vector<std::unique_ptr<Sensor>> mSensors;
};

SensorManager::SensorManager(SensorScanner& sensorScanner,
                             SensorFactory& sensorFactory)
{
    const auto detectedSensorIds = sensorScanner.scan();

    for (const auto& id : detectedSensorIds)
    {
        switch (id)
        {
        case SensorIdentifier::InfraredSensor:
            mSensors.emplace_back(
                sensorFactory.getSensor(SensorType::Infrared));
            break;
        case SensorIdentifier::UltrasonicSensor:
            mSensors.emplace_back(
                sensorFactory.getSensor(SensorType::Ultrasonic));
            break;
        case SensorIdentifier::LaserSensor:
            mSensors.emplace_back(sensorFactory.getSensor(SensorType::Laser));
            break;
        default:
            throw std::logic_error("Unknown sensor");
        }
    }
}
```

| Refactored file(s)                                               | Unit tests                                               |
| ---------------------------------------------------------------- | -------------------------------------------------------- |
| [SensorManager.hpp](040-new_operators/include/SensorManager.hpp) | [SensorManager_test.cpp](test/ut/SensorManager_test.cpp) |
| [SensorManager.cpp](040-new_operators/src/SensorManager.cpp)     |                                                          |


### Time

Very often we need to perform operations that involve time. For example, we may need
to execute some actions at a specific interval, wait until another event happens, a
timeout expires etc. Writing code for this is very straight forward unlike testing it.
To begin with, one should be able to execute unit tests fast to quickly verify the new
functionality they are introducing to the project. Therefore, *waiting* for things
to happen, can significantly delay the test feedback loops. To make things worse, the
period we need to wait might be arbitrarily large (e.g. hours or days) which would deem
any related functionality unfit for unit tests.

#### Example(s)

```cpp
bool PowerController::turnOn()
{
    mPinManager.setPin(kPin);
    std::this_thread::sleep_for(1s);
    mPinManager.clearPin(kPin);

    std::unique_lock<std::mutex> lk(mRunnerMutex);
    std::cout << "Waiting for response" << std::endl;
    mConditionVariable.wait_for(
        lk, 10s, [this]() { return mPulseReceived.load(); });

    return mPulseReceived.load();
}
```

#### Alternative(s)

Testing `turnOn` means we would have to wait for at least 1 second for every test. To
verify we would actually block the execution and wait until the timeout expires, we
would have to wait even longer. If you contemplate upon it, the *actual waiting is not
part of our logic, but a requirement of whatever receives the pulse and sends back a
signal. Instead, we should abstract the time-related operations behind two interfaces.
One that simply "keeps time" or merely blocks the current thread and another to *schedule*
events, such as the timeout expiry.

```cpp
struct MyTimeKeeper : public TimeKeeper
{
    void sleepFor(std::chrono::milliseconds delay) const override;
};

class AsynchronousTimer
{
public:
    virtual ~AsynchronousTimer() = default;

    virtual void schedule(std::function<void()> task,
                          std::chrono::seconds delay)
        = 0;
    virtual bool hasPendingTask() const = 0;
    virtual void abort()                = 0;
};

bool PowerController::turnOn()
{
    mPinManager.setPin(kPin);
    mTimeKeeper.sleepFor(kTimeBetweenPulses);
    mPinManager.clearPin(kPin);

    std::unique_lock<std::mutex> lk(mRunnerMutex);
    std::cout << "Waiting for response" << std::endl;
    mAsynchronousTimer.schedule(
        [this]() {
            mPulseTimedOut = true;
            mConditionVariable.notify_one();
        },
        kTimeToWaitForPulse);

    mConditionVariable.wait(lk, [this]() {
        return mPulseReceived.load() || mPulseTimedOut.load();
    });

    mAsynchronousTimer.abort();
    mPulseTimedOut = false;

    return mPulseReceived.load();
}
```

| Refactored file(s)                                          | Unit tests                                                   |
| ----------------------------------------------------------- | ------------------------------------------------------------ |
| [PowerController.hpp](050-time/include/PowerController.hpp) | [PowerController_test.cpp](test/ut/PowerController_test.cpp) |
| [PowerController.cpp](050-time/src/PowerController.cpp)     |                                                              |

### Law of Demeter

> * Each unit should have only limited knowledge about other units: only units "closely"
> related to the current unit.
> * Each unit should only talk to its friends; don't talk to strangers.
> * Only talk to your immediate friends.
>
> [Source](https://en.wikipedia.org/wiki/Law_of_Demeter)

> The Law of Demeter for functions requires that a method M of an object O may only invoke
> the methods of the following kinds of objects:
>
> 1. O itself
> 2. M’s parameters
> 3. Any objects created/instantiated within M
> 4. O’s direct component objects
> 5. A global variable, accessible by O, in the scope of M
>
> [Source](https://alvinalexander.com/java/java-law-of-demeter-java-examples/)

Violations of the Law of Demeter generally make your software susceptible to changes
of indirect or non-obvious dependencies and violates the object oriented design principle
of the separation of concerns. When it comes to testing, it is a primary suspect for
pulling in unrelated dependencies, since our unit becomes coupled to the resources its
resources utilize.

#### Example(s)

```cpp
struct SerialPortClient
{
    virtual ~SerialPortClient() = default;

    virtual void send(std::string message) const = 0;
};

struct CommunicationManager
{
    virtual ~CommunicationManager() = default;

    virtual void sendViaSerial(std::string message)       = 0;
    virtual SerialPortClient& getSerialPortClient() const = 0;
};

void MyCommunicationManager::sendViaSerial(std::string message)
{
    mSerialPortClient.send(std::to_string(mSequenceNumber++) + ":" + message);
}

SerialPortClient& MyCommunicationManager::getSerialPortClient() const
{
    return mSerialPortClient;
}

void StateBroadcaster::broadcast()
{
    mCommunicationManager.sendViaSerial("get_power");
}

void StateBroadcaster::emergencyBroadcast()
{
    mCommunicationManager.getSerialPortClient().send("emergency");
}
```

#### Alternative(s)

Thankfully, solving this is rather easy in two ways. If your unit needs to use a resource,
then it should do that directly, not through others. However, before injecting and letting
your unit use the resource, one should carefully think of whether it should. Your unit is
likely concerned with something it should not and another class should be hosting that
functionality instead.

```cpp

struct CommunicationManager
{
    virtual ~CommunicationManager() = default;

    virtual void sendViaSerial(std::string message)          = 0;
    virtual void sendViaRawSerial(std::string message) const = 0;
};

void MyCommunicationManager::sendViaSerial(std::string message)
{
    mSerialPortClient.send(std::to_string(mSequenceNumber++) + ":" + message);
}

void MyCommunicationManager::sendViaRawSerial(std::string message) const
{
    mSerialPortClient.send(message);
}

void StateBroadcaster::broadcast()
{
    mCommunicationManager.sendViaSerial("get_power");
}

void StateBroadcaster::emergencyBroadcast()
{
    mCommunicationManager.sendViaRawSerial("emergency");
}
```

| Refactored file(s)                                                                  | Unit tests                                                     |
| ----------------------------------------------------------------------------------- | -------------------------------------------------------------- |
| [CommunicationManager.hpp](060-law_of_demeter/include/CommunicationManager.hpp)     | [StateBroadcaster_test.cpp](test/ut/StateBroadcaster_test.cpp) |
| [MyCommunicationManager.hpp](060-law_of_demeter/include/MyCommunicationManager.hpp) |                                                                |
| [MyCommunicationManager.cpp](060-law_of_demeter/src/MyCommunicationManager.cpp)     |                                                                |
| [StateBroadcaster.hpp](060-law_of_demeter/include/StateBroadcaster.hpp)             |                                                                |
| [StateBroadcaster.cpp](060-law_of_demeter/src/StateBroadcaster.cpp)                 |                                                                |

### Domain logic dependent on application logic

Having the domain/platform logic dependent on the application is one of the most common yet
serious mistakes one can do. It hurts the maintainability, readability and reusability
of software. Eventually makes it unsustainable. A common way to differentiate between
variants is via preprocessor macros. While macros by themselves are usually unnecessary and
are discouraged by the C++ Core guidelines (e.g.
[ES.30](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es30-dont-use-macros-for-program-text-manipulation),
[ES.31](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es31-dont-use-macros-for-constants-or-functions)),
they make things tricky to test. Specifically, the more the variants are, the worse it gets.

#### Example(s)

```cpp
struct CommunicationManager
{
    CommunicationManager(SerialPortClient& serialPortClient);

    void sendViaSerial(std::string message);

private:
    SerialPortClient& mSerialPortClient;
};

void CommunicationManager::sendViaSerial(std::string message)
{
#if defined(FOO_PRODUCT)
    static int sequenceNumber = 0;
    mSerialPortClient.send(std::to_string(sequenceNumber++) + ":" + message);
#elif defined(BAR_PRODUCT)
    mSerialPortClient.send("M:" + message + ",");
#else
#error Did you forget to define a product?
#endif
}
```

#### Alternative(s)

The example is rather simple but (sadly) common and sufficiently thwarts our software's
testability. `CommunicationManager` is a typical platform component that handles
the communication with other parts of the system. The fact that different product variants
communicate over different protocols or formats, should *not* be the platform's concern.
Instead, we create other classes (children of `SerialFormatter`) that encapsulate
product-specific business logic. Rather than awkwardly defining preprocessor symbols, we
inject them into the platform component. More importantly, we can test the platform logic
*independently* from the application functionality across different products.

As a rule of thumb, leaking application-level details into the domain logic is a very strong
code smell and an indication of architectural/design debt.

```cpp
struct SerialFormatter
{
    virtual ~SerialFormatter() = default;

    virtual std::string format(const std::string& input) = 0;
};

std::string BarSerialFormatter::format(const std::string& input)
{
    return "M:" + input + ",";
}

std::string FooSerialFormatter::format(const std::string& input)
{
    return std::to_string(mSequenceNumber++) + ":" + input;
}

struct CommunicationManager
{
    CommunicationManager(SerialPortClient& serialPortClient,
                         SerialFormatter& serialFormatter);

    void sendViaSerial(std::string message);

private:
    SerialPortClient& mSerialPortClient;
    SerialFormatter& mSerialFormatter;
};

void CommunicationManager::sendViaSerial(std::string message)
{
    mSerialPortClient.send(mSerialFormatter.format(message));
}
```

| Refactored file(s)                                                                               | Unit tests                                                             |
| ------------------------------------------------------------------------------------------------ | ---------------------------------------------------------------------- |
| [CommunicationManager.hpp](070-domain_dependent_on_application/include/CommunicationManager.hpp) | [CommunicationManager_test.cpp](test/ut/CommunicationManager_test.cpp) |
| [CommunicationManager.cpp](070-domain_dependent_on_application/src/CommunicationManager.cpp)     |                                                                        |

## License

* Code is licensed under [MIT license](LICENSE)
* Markdown files are licensed under [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/)
