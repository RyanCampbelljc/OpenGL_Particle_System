in vec4 a_position;
in vec4 a_color;
out vec4 v_color;
out vec4 v_position;
void main(){
    gl_Position = a_position; 
    v_color = a_color;
    v_position = a_position;
}