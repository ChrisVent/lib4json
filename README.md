lib4json
=========
Minimalist JSON API Library for C

Using
---------

####Include
clone this repository in your project folder and include it:
```c
#include "lib4json/lib4json.c"
```

####Documentation

```c

// create json string {"username":"Admin","admin":true}
const char* json = "{\"username\":\"Admin\",\"admin\":true}";

jsonObject myJson = jsonParse(json); //create json object and parse the string
printJsonParsed(myJson);

/* Output --->

    [ Hobbies ]: ["golf","rubik"]   (Type: Array)
    [ admin ]: true (Type: Boolean)
    [ name ]: Christian Brown   (Type: String)
    [ pass ]: Lorem123  (Type: String)
    [ username ]: Admin (Type: String)
    [ userID ]: 1   (Type: Number)

*/
//save the keys in array
char** keys = getJsonKeys(myJson);
int i;
for(i = 0 ; i < myJson.size ; i++){
    printf("Key: %s\n",keys[i]);
}
/* Output -->

    Key: Hobbies
    Key: admin
    Key: name
    Key: pass
    Key: username
    Key: userID

*/

free(keys);


//save the values in array
char** values = getJsonValues(myJson);
int i;
for(i = 0 ; i < myJson.size ; i++){
    printf("Value: %s\n",values[i]);
}
/* Output -->

    Value: ["golf","rubik"]
    Value: true
    Value: Christian Brown
    Value: Lorem123
    Value: Admin
    Value: 1

*/

free(values);
```
