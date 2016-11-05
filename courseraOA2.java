/*
 * Complete the function below.
 *
 * Sample Input 1
 * 1470096000000
 * 2
 * 1470787200000
 * 
 * Sample Output 1
 * 1471824000000
 * 1473033600000
 * 1474243200000
 *
 * Sample Input 2
 * 1470700800000
 * 1
 * 1470096000000
 * 
 * Sample Output 2
 * 1471219200000
 * 1471824000000
 * 1472428800000
 */
    //total seconds of a day
    private static final long SECONDS_OF_A_DAY = 86400L;
    //total seconds of a week
    private static final long SECONDS_OF_A_WEEK = 604800L;
    //Calendar.DAY_OF_WEEK, Monday == 2
    private static final int MONDAY = 2;

    /**
     * @param launchDate: course launch date
     * @param repeatFrequency: course repeat frequency
     * @param enrollmentDate: enroll date of the course
     * @return next three valid sessions
     */
    static long[] getUpcomingSessions(long launchDate, int repeatFrequency, long enrollmentDate) {
        //set timezone to "GMT"
        Calendar calendar = Calendar.getInstance(TimeZone.getTimeZone("GMT"));
        calendar.setTimeInMillis(launchDate);
        int dayOfWeek = calendar.get(Calendar.DAY_OF_WEEK);
        
        //find next valid Monday that can start a course session
        while (dayOfWeek != MONDAY) {
            launchDate += SECONDS_OF_A_DAY * 1000;
            calendar.setTimeInMillis(launchDate);
            dayOfWeek = calendar.get(Calendar.DAY_OF_WEEK);
        }
        
        //find a proper launchDate
        while (enrollmentDate > launchDate) {
            launchDate += SECONDS_OF_A_WEEK * 1000 * repeatFrequency;
        }

        //results
        long[] rtn = new long[3];
        rtn[0] = launchDate;
        rtn[1] = rtn[0] + SECONDS_OF_A_WEEK * 1000 * repeatFrequency;
        rtn[2] = rtn[1] + SECONDS_OF_A_WEEK * 1000 * repeatFrequency;
        return rtn;
    }

/*
 * Complete the function below.
 */
    //total seconds of a day
    private static final long SECONDS_OF_A_DAY = 86400L;
    //total seconds of a week
    private static final long SECONDS_OF_A_WEEK = 604800L;
    //Calendar.DAY_OF_WEEK, Monday==2
    private static final int MONDAY = 2;

    /**
     * @param specializationCourses:launch_date, repeat_frequency, duration 
     * @param enrollmentDate: date user enrolls in specialization
     * @return course session schedule
     */
    static long[][] getSpecializationSessionSchedule(long[][] specializationCourses, long enrollmentDate) {
        Calendar calendar = Calendar.getInstance(TimeZone.getTimeZone("GMT"));
        int rows = specializationCourses.length;
        
        //the earliest start date for a course
        //either first course enroll date or last course end date
        long lastEndDate = enrollmentDate;

        long[][] results = new long[rows][2];

        for (int i = 0; i < rows; i++) {
            long launchDate = specializationCourses[i][0];
            long freq = specializationCourses[i][1];
            long duration = specializationCourses[i][2];
            calendar.setTimeInMillis(launchDate);
            int dayOfWeek = calendar.get(Calendar.DAY_OF_WEEK);
            
            while (dayOfWeek != MONDAY) {
                launchDate += SECONDS_OF_A_DAY * 1000;
                calendar.setTimeInMillis(launchDate);
                dayOfWeek = calendar.get(Calendar.DAY_OF_WEEK);
            }
            
            //find a proper launchDate
            while (enrollmentDate > launchDate || launchDate < lastEndDate) {
                launchDate += SECONDS_OF_A_WEEK * 1000 * freq;
            }
            
            results[i][0] = launchDate;
            results[i][1] = launchDate + SECONDS_OF_A_WEEK * 1000 * duration;
            lastEndDate = results[i][1];
        }
        return results;
    }

