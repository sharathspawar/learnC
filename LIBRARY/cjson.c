#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"  // Include the CJSON header

int main() {
    // Example JSON string to parse. This string represents a JSON object
    // with "name", "age", and "city" fields.
    const char* json_string = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";

    // Parse the JSON string into a cJSON object. cJSON_Parse() takes a JSON
    // string as input and returns a pointer to a cJSON structure representing
    // the parsed JSON data. If parsing fails (e.g., invalid JSON format), it
    // returns NULL.  'root' will point to the root of the JSON object tree.
    cJSON* root = cJSON_Parse(json_string);
    if (root == NULL) {
        printf("Error parsing JSON\n"); // Handle parsing error
        return 1; // Indicate an error
    }

    // Access values within the JSON object using cJSON_GetObjectItem(). This
    // function takes the root cJSON object and a key (string) as input. It
    // searches the JSON object for a member with the given key and returns
    // a pointer to the cJSON item if found, otherwise returns NULL.
    cJSON* name = cJSON_GetObjectItem(root, "name");
    cJSON* age = cJSON_GetObjectItem(root, "age");
    cJSON* city = cJSON_GetObjectItem(root, "city");

    // Print the accessed values. Check if the returned pointers are not NULL
    // before accessing their values to prevent segmentation faults. Access
    // the values based on their type.  `valuestring` is used for strings,
    // `valueint` for integers, etc.
    if (name) printf("Name: %s\n", name->valuestring);
    if (age) printf("Age: %d\n", age->valueint);
    if (city) printf("City: %s\n", city->valuestring);


    // Modify the JSON object. cJSON_SetValuestring() changes the value of
    // an existing string member.  cJSON_SetNumberValue() changes the value
    // of an existing numeric member.  These functions modify the cJSON object
    // in place.
    cJSON_SetValuestring(name, "Alice");  // Change name to "Alice"
    cJSON_SetNumberValue(age, 25);        // Change age to 25

    // Add a new array to the JSON object.  cJSON_CreateArray() creates an
    // empty JSON array.  cJSON_AddItemToArray() adds items to the array.
    // cJSON_CreateString() creates a cJSON item that holds a string value.
    cJSON* hobbies = cJSON_CreateArray();
    cJSON_AddItemToArray(hobbies, cJSON_CreateString("Reading"));
    cJSON_AddItemToArray(hobbies, cJSON_CreateString("Cycling"));
    cJSON_AddItemToObject(root, "hobbies", hobbies);  // Add hobbies array to the root object

    // Generate the updated JSON string using cJSON_Print(). This function takes
    // a cJSON object and creates a formatted JSON string representation of it.
    // The returned string is dynamically allocated, so it must be freed using
    // free() when no longer needed.
    char* updated_json_string = cJSON_Print(root);
    printf("\nUpdated JSON: %s\n", updated_json_string);

    // Add a nested object to the JSON. Create a new JSON object for the address
    // and add key-value pairs to it.  This illustrates how to create nested
    // JSON structures.
    cJSON* address = cJSON_CreateObject();
    cJSON_AddStringToObject(address, "street", "5th Avenue"); // Convenience function to add string items
    cJSON_AddStringToObject(address, "zipcode", "10001");    // Another string item
    cJSON_AddItemToObject(root, "address", address);  // Add 'address' object to the 'root' object

    // Generate a new JSON string showing the final structure with the nested object.
    char* final_json_string = cJSON_Print(root);
    printf("\nFinal JSON with address: %s\n", final_json_string);

    // Free the dynamically allocated JSON strings. It's essential to free memory
    // to prevent memory leaks, especially when dealing with dynamically
    // allocated strings.
    free(updated_json_string);
    free(final_json_string);

    // Clean up the cJSON object tree.  cJSON_Delete() recursively frees all
    // memory associated with the given cJSON object and its children.  This is
    // a crucial step to prevent memory leaks.
    cJSON_Delete(root);

    return 0; // Indicate successful completion
}


// Explanation of the Program:

//     Parsing JSON:
//         The program starts by parsing a simple JSON string with three key-value pairs: name, age, and city.

//     Accessing JSON Data:
//         The program retrieves values from the parsed JSON object using cJSON_GetObjectItem().
//         It prints the values of "name", "age", and "city".

//     Modifying JSON Data:
//         The program modifies the values of "name" and "age" using cJSON_SetValuestring() and cJSON_SetNumberValue().

//     Adding Data:
//         The program adds a new array "hobbies" to the JSON object. This array contains two items: "Reading" and "Cycling".
//         It also adds a nested object "address", which contains the "street" and "zipcode" fields.

//     Generating JSON:
//         After modifying the data, the program serializes the updated JSON object back into a string using cJSON_Print().
//         It prints the updated JSON and also the final JSON with the new "address" object added.

//     Memory Management:
//         The program uses free() to release memory for the JSON strings created using cJSON_Print().
//         The program also properly frees the entire cJSON object using cJSON_Delete() to avoid memory leaks.




// Key Functions Used in the Program:

//     cJSON_Parse(): Parses a JSON string into a cJSON object.
//     cJSON_GetObjectItem(): Accesses a value by key from the JSON object.
//     cJSON_SetValuestring(): Sets a string value for a JSON object.
//     cJSON_SetNumberValue(): Sets a numeric value for a JSON object.
//     cJSON_CreateArray() and cJSON_CreateObject(): Creates a new JSON array or object.
//     cJSON_AddItemToObject() and cJSON_AddStringToObject(): Adds new items or key-value pairs to a JSON object.
//     cJSON_Print(): Serializes a cJSON object to a string.
//     cJSON_Delete(): Frees the memory used by a cJSON object.

// Conclusion:

// This program demonstrates how to use the CJSON library to parse, modify, and generate JSON data in C. It's a simple yet powerful way to handle JSON in C applications, such as reading configuration files, working with APIs, or managing data structures in a readable and efficient format. By combining all the operations into a single program, you can see the flow of working with JSON in a real-world scenario.




// CJSON is a C library designed for parsing and manipulating JSON (JavaScript Object Notation) data. It allows C programs to easily handle JSON data, whether it's reading, writing, or modifying it.

// JSON is a widely-used lightweight data interchange format that is easy for humans to read and write, and easy for machines to parse and generate. CJSON simplifies working with JSON data in C by providing a simple API.
// Key Features of CJSON:

//     Parsing: Converts JSON data (in text form) into C data structures (such as arrays, objects, and primitive types).
//     Serialization: Converts C data structures into JSON format (to be written to files, sent over networks, etc.).
//     Modification: Allows adding, removing, or modifying elements in a JSON object.
//     Memory Management: Manages memory for the parsed JSON data, and provides functions to free allocated memory.

// Basic Operations in CJSON:

//     Parsing JSON: Convert a JSON string into a C data structure.
//     Accessing Data: Retrieve values from the parsed JSON object.
//     Modifying Data: Modify values in a JSON object.
//     Generating JSON: Convert C data back into a JSON string.
//     Freeing Memory: Ensure that any allocated memory is properly freed.

// Installation:

// To use CJSON, you can download the library from its GitHub repository: CJSON GitHub Repository.

// Once you've downloaded or cloned the repository, you can build the library by compiling the cJSON.c file along with your own code.

// Alternatively, if you are using a package manager like apt on Linux, you might be able to install CJSON using:

// sudo apt-get install libcjson-dev


// Explanation:

//     Parsing JSON:
//         cJSON_Parse(json_string) parses the JSON string into a cJSON object. If parsing fails, it returns NULL.
//         In this example, the JSON string contains name, age, and city.

//     Accessing JSON Data:
//         cJSON_GetObjectItem(root, "name") retrieves the value associated with the "name" key.
//         The returned item can be accessed depending on its type. In this case, valuestring (for string values) and valueint (for integer values) are used to access the name, age, and city values.

//     Modifying JSON Data:
//         cJSON_SetValuestring(name, "Alice") changes the value of "name" to "Alice".
//         cJSON_SetNumberValue(age, 25) changes the "age" to 25.

//     Generating JSON:
//         cJSON_Print(root) converts the modified cJSON object back into a JSON string.

//     Memory Management:
//         cJSON_Delete(root) frees the memory associated with the cJSON object.
//         free(updated_json_string) frees the memory allocated for the string representation of the updated JSON.

// CJSON Functions Overview:

// Here are some important functions in the CJSON library:

//     cJSON_Parse(const char* json_string): Parses a JSON string into a cJSON object.
//     cJSON_Print(const cJSON* item): Converts a cJSON object into a formatted JSON string.
//     cJSON_GetObjectItem(const cJSON* object, const char* string): Retrieves an item from a JSON object by key.
//     cJSON_SetValuestring(cJSON* item, const char* string): Sets a string value for a cJSON object.
//     cJSON_SetNumberValue(cJSON* item, double num): Sets a numeric value for a cJSON object.
//     cJSON_Delete(cJSON* item): Frees memory allocated for a cJSON object



// Expected Output:

// Name: John
// Age: 30
// City: New York

// Updated JSON: {"name":"Alice","age":25,"city":"New York","hobbies":["Reading","Cycling"]}

// Final JSON with address: {"name":"Alice","age":25,"city":"New York","hobbies":["Reading","Cycling"],"address":{"street":"5th Avenue","zipcode":"10001"}}
