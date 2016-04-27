#include "../lib4json.c"

int main (int args, const char *argv[]){
    // #    create the json string
    const char* json = "{\"userID\":1,\"username\":\"Admin\",\"pass\":\"Lorem123\",\"name\":\"Christian Brown\",\"admin\":true,\"Hobbies\":[\"golf\",\"rubik\"]}";
    // #    create json object and parse the string
    jsonObject myJson = jsonParse(json);
    //addJsonItem_String(&myJson,"foo","bar"); // no do this! (in beta);
    printJsonParsed(myJson);
    /* Output --->

        [ Hobbies ]: ["golf","rubik"]   (Type: Array)
        [ admin ]: true (Type: Boolean)
        [ name ]: Christian Brown   (Type: String)
        [ pass ]: Lorem123  (Type: String)
        [ username ]: Admin (Type: String)
        [ userID ]: 1   (Type: Number)

    */
    //save the values in array
    char** values = getJsonValues(myJson);
    printf("\n====================================\n\n");
    int j;
    for(j = 0 ; j < myJson.size ; j++){
        fprintf(stdout,"Value: %s\n",values[j]);
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

    //save the keys in array
    char** keys = getJsonKeys(myJson);
    int i;
    printf("\n====================================\n\n");
    for(i = 0 ; i < myJson.size ; i++){
        fprintf(stdout,"Key: %s\n",keys[i]);
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






    // empty json for add Items (coming)
    jsonObject AnotherJson = initJSON();
    return 0;
}
