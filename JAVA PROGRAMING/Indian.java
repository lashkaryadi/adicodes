class Fruits{
    void input(){
        String y = "juicy";
        System.out.println(y);
    }
}
class Apple extends Fruit{ 
    
    void disp(){
        String x = "indian";
        System.out.println(x);
    }
}
class Indian extends Apple{
    void disp2(){
        System.out.println("Kashmiri");
    }
    public static void main (String[] args){
        Indian i= new Indian();
        
        i.disp2();
    }
}