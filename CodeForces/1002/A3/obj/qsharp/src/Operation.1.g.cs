#pragma warning disable 1591
using System;
using Microsoft.Quantum.Primitive;
using Microsoft.Quantum.Simulation.Core;
using Microsoft.Quantum.MetaData.Attributes;

[assembly: OperationDeclaration("Solution", "Solve (qs : Qubit[]) : Int", new string[] { }, "/home/monman/online_judge/CodeForces/1002/A3/Operation.1.qs", 144L, 6L, 5L)]
#line hidden
namespace Solution
{
    public class Solve : Operation<QArray<Qubit>, Int64>, ICallable
    {
        public Solve(IOperationFactory m) : base(m)
        {
        }

        String ICallable.Name => "Solve";
        String ICallable.FullName => "Solution.Solve";
        protected ICallable<Qubit, Result> M
        {
            get;
            set;
        }

        public override Func<QArray<Qubit>, Int64> Body => (__in) =>
        {
            var qs = __in;
            // your code here
#line 10 "/home/monman/online_judge/CodeForces/1002/A3/Operation.1.qs"
            var res = 0L;
#line 11 "/home/monman/online_judge/CodeForces/1002/A3/Operation.1.qs"
            foreach (var i in new Range(0L, (qs.Count - 1L)))
            {
#line 12 "/home/monman/online_judge/CodeForces/1002/A3/Operation.1.qs"
                var m = M.Apply(qs[i]);
#line 13 "/home/monman/online_judge/CodeForces/1002/A3/Operation.1.qs"
                if ((m == Result.One))
                {
#line 14 "/home/monman/online_judge/CodeForces/1002/A3/Operation.1.qs"
                    res = 1L;
                }
            }

#line 17 "/home/monman/online_judge/CodeForces/1002/A3/Operation.1.qs"
            return res;
        }

        ;
        public override void Init()
        {
            this.M = this.Factory.Get<ICallable<Qubit, Result>>(typeof(Microsoft.Quantum.Primitive.M));
        }

        public override IApplyData __dataIn(QArray<Qubit> data) => data;
        public override IApplyData __dataOut(Int64 data) => new QTuple<Int64>(data);
        public static System.Threading.Tasks.Task<Int64> Run(IOperationFactory __m__, QArray<Qubit> qs)
        {
            return __m__.Run<Solve, QArray<Qubit>, Int64>(qs);
        }
    }
}