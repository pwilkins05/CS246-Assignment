using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
/// <summary>
/// Marti Garcia
/// CS 246
/// </summary>
public class HiraganaDict
{
    static Dictionary<string, string> dictionary;

    public Dictionary<string, string> HiraganaDictionary()
    {
        dictionary = new Dictionary<string, string>()
        {
            {"あ", "a"},{"い", "i"},{"う", "u"},{"え", "e"},{"お", "o"},{"か", "ka"},{"き", "ki"},{"く", "ku"},
            {"け", "ke"},{"こ", "ko"},{"さ", "sa"},{"し", "shi"},{"す", "su"},{"せ", "se"},{"そ", "so"},
	    };
        return dictionary;
    }

    private List<int> RandomWordKeys()  //Bug: Should be List<string> not List<int>
    {
        // Gets 5 random keys from dictionary
        List<string> keyList = new List<string>();
        dictionary = HiraganaDictionary();
        keyList = dictionary.Keys.ToList();
        Random r = new Random();
        List<string> randKeyList = new List<string>();
        for (int i = 0; i <= 5; i++)  //Bug: should be i < 5 not i <= 5
        {
            int index = r.Next(keyList.Count);
            randKeyList.Add(keyList[index]);
            keyList.RemoveAt(index);
        }
        return keyList; //Bug: should be returning randKeyList, not keyList
    }
}