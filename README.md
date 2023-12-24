# solorolo
  
This is a FOS(S) set of code and CAD files to assist in creating a single hub motor self balancing skateboard. As I said, this is provided for free. I take no responsibility for whatever may happen with creation of devices from these files. You are (at) your own risk. Please don't ask me about named collection specifics, but instead speak with the contributer for it.  
  
That being said, riding around on this thing has been amazing and it has been a great time putting it together. Thanks for the interest. :)  
  
I would start with the BOM and the README files within this repo if you're experienced in PEV building.  
  
**In specific my recommend for creation of a SoloRolo is loosely this order, and it should be inferred that if a named collection does not have an entry in any subsection that `orignal` is to be used:**
1. Take note of the structure of files here so you know you're getting everything you need. It's actually easier done than said.
2. Read about and print/PIM/order [plastics](mechanical/plastics/PLASTICS.md) as they will take a "long time" to print, even if ordering from a 3D print or PIM company. This is the choice likely to have the most effect on look/feel and other part requirements. Start printing the electronics plate first if you have to make a choice, followed by the resistive footpad.
3. Start putting together and making orders for your parts based on the [original BOM](BOMs/original/BOM.md). Preferably starting with your frame material in the next step so you can deliberate and not delay your whole project. If there are different requirements for your named collection they'll be found in [BOMs](BOMs/).
4. Start assembling your electronics. Take your time, and do a good job.
5. Read about and cut/order your [metals](mechanical/metals/METALS.md). Check for a [metals](metals/) subsection for your chosen named collection (or use `original`), and start cutting.
6. Now that you have a metal frame to more reasonably mount and attach the hub motor and ESC parts to read about and program your [ESC](electronics/ESCs/). These can be expensive and should be the first thing to verify. Any differing files from the VESC based FESC will be under it's respective subsection.
7. LEDs! And... everything else. You'll need to wait for your electronics plate print. Run all your wires through your frames, stick all your LEDs on the frame that are going there, and mount your electronics to your electronics plate. This will allow easier access to everything as it's all coming together now! :D Absolutely consult the [electronics schematic](electronics/schematics/) for your named collection (or `original`).
8. Program your Arduino, lighting controller, or whatever your named collection specifies and test the lights. Usually you can test by mounting your frame to a milk carton and tilting it while applying pressure to to the resistive sensors to verify proper power connections, communication between the lighting controller and the ESC, and proper power and/or data between the lighting controller and the LEDs and or strips.
9. When all your prints are in, assemble all the things! Fasten your cavities to your frame after fishing your wires through during assembly, install all your external interfaces (charge inlet, power button, LEDs and/or strips, screens, readouts, etc), connect all the loose power and data wires according to the [electronics schematic](electronics/schematics/) for your named collection (or `original`), fasten your footpads to your cavities, and install any caps or friction coatings (skateboard tape).
10. Test all your functions using your milk crate mount or whatever you've devised, and take 'er out on a catious maiden voyage! Roll! You're probably done! :D  
