using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Formulas : MonoBehaviour
{
    public bool checkFormula;

    public float sqrMagnitudeAnswer;

    public Vector2 input;

    void Start()
    {
        
    }

    void Update()
    {
        if (checkFormula)
        {
            if (sqrMagnitudeAnswer == input.sqrMagnitude) print("Answer correct");
            else print("Answer wrong");
            print("Answer: " + input.sqrMagnitude);
            checkFormula = false;
        }
    }
}