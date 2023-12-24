# SoloRolo
  
This is a FOS(S) set of code and CAD files to assist in creating a single hub motor self balancing skateboard. As I said, this is provided for free. I take no responsibility for whatever may happen with creation of devices from these files. You are (at) your own risk. Please don't ask me about named collection specifics, but instead speak with the contributer for it.  
  
That being said, riding around on this thing has been amazing and it has been a great time putting it together. Thanks for the interest. :)  
  
TL;DR for `original` SoloRolo:  
1. choose a battery size using notes at the bottom of this README  
2. choose if you want nice LED headlights (does not effect battery life worth talking about)
3. choose if you want underglow (RGB, can chase ground with rainbow)
4. choose LED strip types (individually addressable [RGB], RGB "analog")
5. download+print [these](mechanical/plastics/)  
6. order [these](BOMs/original/)  
7. check+cut [these](mechanical/metals/original/)  
8. assemble *everything* using [this](electrical/original/) and [this](finished/original/)  
9. program [ESC](code/ESCs/original/) and [Arduino](code/controllers/original/)  
10. button up and roll  
  
**In specific my recommend for creation of a SoloRolo is loosely this order, and it should be inferred that if a named collection does not have an entry in any subsection that `orignal` is to be used:**
1. Take note of the structure of files here so you know you're getting everything you need. It's actually easier done than said.
2. Read about and print/PIM/order [plastics](mechanical/plastics/) as they will take a "long time" to print, even if ordering from a 3D print or PIM company. This is the choice likely to have the most effect on look/feel and other part requirements. Start printing the electronics plate first if you have to make a choice, followed by the resistive footpad.
3. Start putting together and making orders for your parts based on the [original BOM](BOMs/original/). Preferably starting with your frame material from the next step so you can deliberate on certain details without delaying your whole project. If there are different requirements for your named collection they'll be found in [BOMs](BOMs/).
4. Start assembling your electronics. Take your time, and do a good job.
5. Read about and order/cut your [metals](mechanical/metals/). Check for a subsection for your chosen named collection (or use `original`), and start cutting.
6. Now that you have a metal frame to more reasonably mount and attach the hub motor and ESC parts to read about and program your [ESC](electronics/ESCs/). These can be expensive and should be the first thing to verify. Any differing files from the VESC based FESC will be under it's respective subsection.
7. LEDs! And... everything else. You'll need to wait for your electronics plate print. Run all your wires through your frames, stick all your LEDs on the frame that are going there, and mount your electronics to your electronics plate. This will allow easier access to everything as it's all coming together now! :D Absolutely consult the [electronics schematic](electronics/) for your named collection (or `original`).
8. Program your Arduino, lighting controller, or whatever your named collection specifies and test the lights. Usually you can test by mounting your frame to a milk carton and tilting it while applying pressure to to the resistive sensors to verify proper power connections, communication between the lighting controller and the ESC, and proper power and/or data between the lighting controller and the LEDs and or strips.
9. When all your prints are in, assemble all the things! Fasten your cavities to your frame after fishing your wires through during assembly, install all your external interfaces (charge inlet, power button, LEDs and/or strips, screens, readouts, etc), connect all the loose power and data wires according to the [electronics schematic](electronics/) for your named collection (or `original`), fasten your footpads to your cavities, and install any caps or friction coatings (skateboard tape).
10. Test all your functions using your milk crate mount or whatever you've devised, and take 'er out on a catious maiden voyage! Roll! You're probably done! :D  

## The `solorolo_` * `_` * `-`* files subsections, and notes:  
***The first wildcard represents the design name of the parts collection.***  
I designed and uploaded `original`. If I don't like a design change to my orignal designs you can make your own (even if you want to start with mine as a base!) and contribute it under new directory names for replacement/required files.

***The second wildcard represents a battery size.***  
While having a large battery can be a benefit there are a few drawbacks such as weight, length, and usable capacity. The `max` size battery is 48 volts with a ? Amp hour (~960 Watt hour) rating yielding loosely 50-60 miles (85-90 kilometers) per full charge.  
- The weight of the `max` size battery SoloRolo is ~37 pounds (~16.75 kilograms). Is it worth lugging this around?  
<sub>It is for me... I live in a relatively remote area, this is great for exploring where I am not likely to use my SoloRolo for bunny hoping between many indoor locations where I may be able to charge.</sub>
  
- With the `max` size battery at maybe 60 miles (90 kilometers) capacity per charge combined with loosely what is considered a reasonable safe top speed of 18 m/h (~30 km/h) you could potentially be riding for 3 hours and 20 minutes! Will you come close to using this capacity?  
<sub>While rolling is an excellent time, that is a decently long duration that you may never approach with chargers at your stops. Again, I live in a relatively remote area.</sub>
  
- The length of the `max` size battery will limit the terrain and/or incline you are trying to travel. Do you have any steep streets you're looking to roll on?  
<sub>For me there are many steep paved and unpaved paths I take, but even so I can often find a another way up/down.</sub>
  
  
***The third and final wildcard represents the name of the part in the size and collection.***  
