/************************************************************************************
 * Filename: Unittest1.c
 * Author : Steve and Swarupa
 *
 * Description : This file tests each and every functionality used individually using CUnits
 *
 * *********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include "CUnit/Basic.h"
#include "inc/main.h"


/*initiating suite*/
int init_suite_init_CB(void)
{
	return 0;
}

int init_suite_insert_data(void)
{
	init_CB(8);
	return 0;

}


int init_suite_delete_data(void)
{
	init_CB(1);
	insert_data('s');
	return 0;
}

int init_suite_report_data(void)
{
	init_CB(4);
	insert_data('s');
	insert_data('t');
	return 0;
}

int init_suite_resize_and_clean(void)
{
	init_CB(2);
	insert_data('s');
	insert_data('t');
	return 0;
}
/*Cleaning suite*/
int clean_suite(void)
{
	return 0;
}

/*Adding test registry*/
void test_init_CB() //suite1
{
	CU_ASSERT_NOT_EQUAL(insert_data('0'),1);
	CU_ASSERT_NOT_EQUAL(delete_data(),1);
	CU_ASSERT_NOT_EQUAL(report_data(),1);
	CU_ASSERT_NOT_EQUAL(clear_buffer(),1);
	CU_ASSERT_NOT_EQUAL(resize_CB(3),1);

	CU_ASSERT_EQUAL(init_CB(3), 1);
	CU_ASSERT_NOT_EQUAL(init_CB(-1), 1);
	CU_ASSERT_NOT_EQUAL(init_CB(0), 1);


}

void test_insert_data() //suite2
{
	CU_ASSERT_EQUAL(insert_data('A'),1);
	CU_ASSERT_EQUAL(insert_data('0'),1);
	CU_ASSERT_EQUAL(insert_data('&'),1);
	CU_ASSERT_EQUAL(insert_data(','),1);
	CU_ASSERT_EQUAL(insert_data('\n'),1);
	CU_ASSERT_EQUAL(insert_data(' '),1);
	CU_ASSERT_EQUAL(insert_data('z'),1);
	CU_ASSERT_EQUAL(insert_data('\\'),1);



	CU_ASSERT_NOT_EQUAL(insert_data('5'),1);
	CU_ASSERT_NOT_EQUAL(insert_data('a'),1);

}

void test_delete_data() //suite3
{
    CU_ASSERT_EQUAL(delete_data(),1);
    CU_ASSERT_NOT_EQUAL(delete_data(),1);
}

void test_report_data() //suite4
{
    CU_ASSERT_EQUAL(report_data(),1);
	CU_ASSERT_EQUAL(delete_data(),1);
    CU_ASSERT_EQUAL(report_data(), 1);
   	CU_ASSERT_EQUAL(delete_data(),1);
	CU_ASSERT_NOT_EQUAL(report_data(), 1);

}

void test_resize_CB() //suite5
{
	CU_ASSERT_NOT_EQUAL(insert_data('A'),1);
	CU_ASSERT_EQUAL(resize_CB(1),1);
	CU_ASSERT_EQUAL(insert_data('B'),1);
	CU_ASSERT_NOT_EQUAL(insert_data('B'),1);

	CU_ASSERT_NOT_EQUAL(resize_CB(-2),1);
	CU_ASSERT_NOT_EQUAL(resize_CB(0),1);

}

void test_clear_buffer() //suite5
{
    CU_ASSERT_EQUAL(clear_buffer(),1);
    CU_ASSERT_NOT_EQUAL(clear_buffer(),1);

}

/*main function*/
int main(void)
{
	 if (CUE_SUCCESS != CU_initialize_registry())
	return CU_get_error();

	CU_pSuite pSuite1 = NULL;
    /* initialize the CUnit test registry */
   

 	/* add a suite to the registry */
 	pSuite1 = CU_add_suite("Suite_1", init_suite_init_CB, clean_suite);
    if (NULL == pSuite1)
    {
	 	CU_cleanup_registry();
	    return CU_get_error();
	}

    /* add the tests to the suite */
    /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
    if ((NULL == CU_add_test(pSuite1, "test of fprintf()", test_init_CB)))
    {
	    CU_cleanup_registry();
      	return CU_get_error();
	}
/***************************************************************************/

	CU_pSuite pSuite2 = NULL;
    
 	/* add a suite to the registry */
 	pSuite2 = CU_add_suite("Suite_2", init_suite_insert_data, clean_suite);
    if (NULL == pSuite2)
    {
	 	CU_cleanup_registry();
	    return CU_get_error();
	}


	if ((NULL == CU_add_test(pSuite2, "test of fprintf()", test_insert_data)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

/***************************************************************************/

	CU_pSuite pSuite3 = NULL;
    

 	/* add a suite to the registry */
 	pSuite3 = CU_add_suite("Suite_3", init_suite_delete_data, clean_suite);
    if (NULL == pSuite3)
    {
		CU_cleanup_registry();
	    return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite3, "test of fprintf()", test_delete_data)))
	{
	    CU_cleanup_registry();
	    return CU_get_error();
	}
/***************************************************************************/

	CU_pSuite pSuite4 = NULL;
    

 	/* add a suite to the registry */
 	pSuite4 = CU_add_suite("Suite_4", init_suite_report_data, clean_suite);
    if (NULL == pSuite4)
    {
		CU_cleanup_registry();
	    return CU_get_error();
	}
	if ((NULL == CU_add_test(pSuite4, "test of fprintf()", test_report_data)))
	{
	        CU_cleanup_registry();
	        return CU_get_error();
	}
/***************************************************************************/

	CU_pSuite pSuite5 = NULL;
    

 	/* add a suite to the registry */
 	pSuite5 = CU_add_suite("Suite_5", init_suite_resize_and_clean, clean_suite);
    if (NULL == pSuite5)
    {
		CU_cleanup_registry();
	    return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite5, "test of fprintf()", test_resize_CB)))
	{
	        CU_cleanup_registry();
	        return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite5, "test of fprintf()", test_clear_buffer)))
	{
	        CU_cleanup_registry();
	        return CU_get_error();
	}

/***************************************************************************/
    /* Run all tests using the CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}

