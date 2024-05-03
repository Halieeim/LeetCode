class Solution {
    public String simplifyPath(String path) {
        if(path.equals("/")) return path;
        path = path.replaceAll("/+", "/");
        if (path.charAt(path.length() - 1) == '/') path = path.substring(0, path.length() - 1);
        if (path.length() > 0 && path.charAt(0) == '/') path = path.substring(1, path.length());
        String[] words = path.split("/");
        String res = "";
        for (String s : words) {
            if (s.equals("..") && res.length() == 0) continue;
            else if (s.equals("..")) {
                res = res.substring(0, res.lastIndexOf("/"));
                continue;
            } else if (s.equals(".")) continue;
            res += "/" + s;
        }
        res = res.replaceAll("/+", "/");
        return res.length() > 0 ? res : "/";
    }
}