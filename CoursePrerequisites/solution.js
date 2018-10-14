type Course = {
    courseId: String,
    skillsNeeded: String[],
    skillsTaught: String[],
}


class CSCurriculum {
    constructor() {
        this.courses = {};
        this.skillsTree = {};
    }

    buildSkillTree() {
        this.skillsTree = {}
        for (let course in courses) {
            const { courseId, skillsTaught } = course;
            for (let skill in skillsTaught) {
                this.skillTree[skill].push(courseId);
            }
        }
    }

    // Simpler for administration, but could be more cumbersome for students
    getSimplestPrerequisites(course) {
        const prerequisites = [];
        const { skillsNeeded } = course;
        for (let skill in skillsNeeded) {
            const simplestCourse = this.skillTree[skill].top();
            prerequisites.push(simplestCourse)
        }
        return prerequisites;
    }

    // Less onerous for students, but could take more thinking from the administration
    getLeastCoursesPrerequisites(course) {
        // TODO
    }
}