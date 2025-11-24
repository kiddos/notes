#include <json-c/json.h>
#include <stdio.h>

void parse_json() {
  const char* json_string =
      "{\"name\": \"Charlie\", \"age\": 45, \"is_developer\": true, \"score\": "
      "98.5}";
  json_tokener* tokener = json_tokener_new();
  // Use -1 to specify the string is null-terminated
  json_object* parsed_json = json_tokener_parse_ex(tokener, json_string, -1);
  enum json_tokener_error jerr = json_tokener_get_error(tokener);

  if (jerr != json_tokener_success || parsed_json == NULL) {
    fprintf(stderr, "Error parsing JSON string: %s\n",
            json_tokener_error_desc(jerr));
    json_tokener_free(tokener);
    return;
  }
  json_tokener_free(tokener);

  json_object* id_obj;
  if (json_object_object_get_ex(parsed_json, "name", &id_obj)) {
    printf("name: %s\n", json_object_get_string(id_obj));
  }

  json_object* age_obj;
  if (json_object_object_get_ex(parsed_json, "age", &age_obj)) {
    printf("age: %d\n", json_object_get_int(age_obj));
  }

  json_object_put(parsed_json);
}

void create_json() {
  json_object* root_obj = json_object_new_object();
  json_object_object_add(root_obj, "id", json_object_new_int(101));
  json_object_object_add(root_obj, "status", json_object_new_string("Active"));
  json_object_object_add(root_obj, "is_valid",
                         json_object_new_boolean(1));

  json_object* hobbies_array = json_object_new_array();
  json_object_array_add(hobbies_array, json_object_new_string("Reading"));
  json_object_array_add(hobbies_array, json_object_new_string("Coding"));
  json_object_array_add(hobbies_array, json_object_new_string("Hiking"));
  json_object_object_add(root_obj, "hobbies", hobbies_array);
  const char* json_output =
      json_object_to_json_string_ext(root_obj, JSON_C_TO_STRING_PRETTY);

  printf("Generated JSON Object:\n");
  printf("%s\n", json_output);

  json_object_put(root_obj);
}

int main(void) {
  parse_json();
  create_json();
  return 0;
}
