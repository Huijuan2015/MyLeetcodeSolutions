public class ValidWordAbbr {
    
    Map< String, Set<String> > mp = new HashMap<>();
    public ValidWordAbbr(String[] dictionary) {
        int len = dictionary.length;
        for(int i = 0; i < len; ++i){
            String s = dictionary[i];
            int sLen = s.length();
            if(s.length() > 2){
                s = s.charAt(0) + Integer.toString(sLen-2) + s.charAt(sLen-1);
            }
            if(mp.containsKey(s)){
                mp.get(s).add(dictionary[i]);
            }else{
                Set<String> set = new HashSet<String>();
                set.add(dictionary[i]);
                mp.put(s, set);
            }
        }
    }

    public boolean isUnique(String word) {
        String s = word;
        int sLen = s.length();
        if(sLen > 2){
           s = s.charAt(0) + Integer.toString(sLen-2) + s.charAt(sLen-1); 
        }
        if(!mp.containsKey(s)) return true;
        else return mp.get(s).contains(word) && mp.get(s).size() <= 1;
    }
}


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa = new ValidWordAbbr(dictionary);
// vwa.isUnique("Word");
// vwa.isUnique("anotherWord");