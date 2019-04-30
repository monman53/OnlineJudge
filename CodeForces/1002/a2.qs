namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[], bits : Bool[]) : ()
    {
        body
        {
            // your code here
            H(qs[0]);
            for(i in 1 .. Length(bits)-1) {
                if(bits[i] == true){
                    CNOT(qs[0], qs[i]);
                }
            }
        }
    }
}
