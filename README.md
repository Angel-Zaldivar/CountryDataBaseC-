# CountryDataBaseC-
The C++ program, "S112-Country-Database-App.cpp," is a program developed in my C++Course, and its primary goal is to establish a country database using parallel vectors. 
These vectors store crucial information like country names, capitals, currencies, and languages. The code incorporates several key functions, including populateVector to
read data from files and fill vectors, printVector for displaying vector contents alongside captions, and findValueVector for executing sequential searches. I've ensured
the database's integrity by comparing the sizes of vectors containing countries, capitals, currencies, and languages.

In the main function, I engage with the user, populating vectors from external files and verifying vector sizes to maintain data consistency. The program offers a menu-driven
system where users can conduct both sequential and binary searches using testSequentialSearch and testBinarySearch, respectively. To exit the interactive search loop, users need
to input "xxx." File paths are currently hardcoded, pointing to files like "vcountry.txt," and I've implemented error handling to address scenarios where files are not found, providing
appropriate error messages.

The structure of the program, coupled with comprehensive documentation, aims to make the code easily understandable for future reference or modifications. Users can input country names
for searches, receiving detailed information about the corresponding country, capital, language, and currency. Overall, this program effectively manages and queries a country database.
