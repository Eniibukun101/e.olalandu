--
-- PostgreSQL database dump
--

-- Dumped from database version 17.2
-- Dumped by pg_dump version 17.2

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET transaction_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: customer_table; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.customer_table (
    c_id integer NOT NULL,
    c_name text NOT NULL,
    c_age integer,
    c_email character varying(20),
    e_id integer NOT NULL,
    data_id integer NOT NULL,
    c_mobile integer
);


ALTER TABLE public.customer_table OWNER TO postgres;

--
-- Data for Name: customer_table; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY public.customer_table (c_id, c_name, c_age, c_email, e_id, data_id, c_mobile) FROM stdin;
110	Musta Karim	35	mkarim@gmail.com	102	5	8055488
11	Lilian Jaiya	43	linsgsg@gmail	100	3	95858
12	Artthur	50	amusa@gmail.com	107	10	584899
113	Philip Akonjo	41	pakinjo@gmail.com	100	2	987789
114	Marylene Mapa	33	mmapa2@gmail.com	120	5	39488474
\.


--
-- PostgreSQL database dump complete
--

