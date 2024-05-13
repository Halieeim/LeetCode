class Twitter {
    
    ArrayList<int[]> allTweets;
    HashMap<Integer,HashMap<Integer,Boolean>> users;

    public Twitter() {
        this.allTweets = new ArrayList<>();
        this.users = new HashMap<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        allTweets.addFirst(new int[] {userId,tweetId});
        addUser(userId);
    }

    private void addUser(int id){
        if(!users.containsKey(id)){
            users.put(id,new HashMap<>());
            users.get(id).put(id,true);
        }
    }
    
    public List<Integer> getNewsFeed(int userId) {
        
        List<Integer> newsFeeds = new ArrayList<>(10);
        for(int[] feed: allTweets){
            if(users.get(userId).containsKey(feed[0])){
                newsFeeds.add(feed[1]);
            }
            if(newsFeeds.size() == 10){
                break;
            }
        }

        return newsFeeds;
    }
    
    public void follow(int followerId, int followeeId) {

        addUser(followerId);
        addUser(followeeId);

        users.get(followerId).put(followeeId,true);
    }
    
    public void unfollow(int followerId, int followeeId) {
        users.get(followerId).remove(followeeId);
    }
}