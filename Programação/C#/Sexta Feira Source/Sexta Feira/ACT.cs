using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sexta_Feira
{
    public class ACT
    {
        


        public static List<string> RDS = new List<string>()
        {
            @"C:\Users\SCP\Desktop\1.txt",
            @"C:\Users\SCP\Desktop\2.txt",
        };

        //IA
        public static StreamReader SR_0 = new StreamReader(RDS[0]);
        //EXEC
        public static StreamReader SR_1 = new StreamReader(RDS[1]);


    }
}
