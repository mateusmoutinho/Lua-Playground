#include "c2wasm.c"
#include "LuaCEmbedOne.c"
#include <stdlib.h>


LuaCEmbedResponse *custom_print(LuaCEmbed *args){

    c2wasm_js_var id_output_view  = c2wasm_create_array();
    c2wasm_append_array_string(id_output_view, "outputView");
    c2wasm_js_var output_view_element = c2wasm_call_object_prop(c2wasm_document,"getElementById", id_output_view);
    

    
   return NULL;
}

c2wasm_js_var execute_lua_machine(){

    c2wasm_js_var id_collect_args  = c2wasm_create_array();
    c2wasm_append_array_string(id_collect_args, "codeEditor");
    c2wasm_js_var text_area_element = c2wasm_call_object_prop(c2wasm_document,"getElementById", id_collect_args);

    long size = c2wasm_get_object_string_len_prop(text_area_element,"value");
    char *code_buffer = malloc(size+1);
    c2wams_object_memcpy_string(text_area_element,"value",0,code_buffer,size);
    code_buffer[size] = '\0';   

   
    c2wasm_js_var id_output_view  = c2wasm_create_array();
    c2wasm_append_array_string(id_output_view, "outputView");
    c2wasm_js_var output_view_element = c2wasm_call_object_prop(c2wasm_document,"getElementById", id_output_view);
    c2wasm_set_object_prop_string(output_view_element,"innerHTML","");

    
    return c2wasm_undefined;
}

int main(){
    c2wasm_start();
    c2wasm_set_object_prop_function(c2wasm_window,"execute_lua_machine",execute_lua_machine);
    return 0;

}