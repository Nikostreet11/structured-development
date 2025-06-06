#ifndef GRADE_MAP_H
#define GRADE_MAP_H

/* Mapping function type */
typedef const char *(*GradeMapper)(int score);

/* Grading strategies */
const char *standard_mapper(int score);
const char *plusminus_mapper(int score);
const char *passfail_mapper(int score);

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

#endif
