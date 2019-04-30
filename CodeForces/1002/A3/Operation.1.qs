namespace Solution {
    open Microsoft.Quantum.Primitive;
    open Microsoft.Quantum.Canon;

    operation Solve (qs : Qubit[]) : Int
    {
        body
        {
            // your code here
            mutable res = 0;
            for(i in 0 .. Length(qs)-1) {
                let m = M(qs[i]);
                if(m == One) {
                    set res = 1;
                }
            }
            return res;
        }
    }
}