Practical references for Unreal Engine.

## C++ & Programming

* [learncpp.com](https://www.learncpp.com/) for C++
* [Game Programming Patterns](https://gameprogrammingpatterns.com/contents.html)
* [Gang of Four Design Patterns](https://www.digitalocean.com/community/tutorials/gangs-of-four-gof-design-patterns)

A friendly note regarding design patterns & code architecture: there's _DEFINITELY_ a point of diminishing returns. If concern over properly architecting your code is getting in the way of actually making your game just write "terrible" code.  When someone's playing your game they don't care _how_ you did it just whether or not it's fun.

## TOOLS

* [renom](https://github.com/UnrealisticDev/Renom) to rename your project (because I always give them goofy names at first)

## Unreal

For the unreal engine site: (1) there should be a dropdown on the top left that you can use to select your version and (2) the API pages (and probably the rest of the site) is hot garbage on mobile.

* [LOGGING](https://unrealcommunity.wiki/logging-lgpidy6i) print messages to the console & screen!
* [Unreal Engine Community Wiki](https://unrealcommunity.wiki/) kinda tough to just browse but it's solid.
* [Unreal Engine Reflection System](https://docs.unrealengine.com/5.2/en-US/reflection-system-in-unreal-engine/) covers C++ macros & keyword specifiers for them that provide engine and editor functionality.
  - [Specifier Docs](https://github.com/benui-dev/UE-Specifier-Docs) Covers all the keyword specifiers in a little more easily navigated format than the official docs
* [ben ui](https://benui.ca/unreal/) collection of tutorials & references
* [Official Documentation](https://docs.unrealengine.com/5.2/en-US/) "complete resource for learning to use Unreal Engine 5"
* [Official API](https://docs.unrealengine.com/5.2/en-US/API/) also just type whatever you're looking for with `C++ Unreal Engine` into any search engine and it should turn up
* [Delegates](https://docs.unrealengine.com/5.2/en-US/ProgrammingAndScripting/ProgrammingWithCPP/UnrealArchitecture/Delegates/) and [Multi-cast Delegates](https://docs.unrealengine.com/5.2/en-US/multicast-delegates-in-unreal-engine/), the latter of which are used in creating custom events for Blueprints
* [Programming Subsystems](https://docs.unrealengine.com/5.2/en-US/programming-subsystems-in-unreal-engine/) a good alternative to Singletons that allow for UE reflection--meaning you can use them in Blueprints.  Be sure to look up them up in the API before you use them.
* [Creating an Editor Module](https://unrealcommunity.wiki/creating-an-editor-module-x64nt5g3) "[A]n editor module allows you to extend the functionality of the editor for your own custom C++ Actors, Components and other classes." All _WITHOUT_ modifying the engine source code!
* [Matthew Wadstein](https://www.youtube.com/@MathewWadsteinTutorials) covers every single blueprint node
* [Prismatic Dev](https://www.youtube.com/@PrismaticaDev/playlists) covers animation along with other topics
